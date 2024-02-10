#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int GRID_SIZE = 10;
const int NUM_TREES = 20;
const int NUM_STONES = 15;
const int NUM_ENEMIES = 3;
char grid[GRID_SIZE][GRID_SIZE];

struct GameObject {
    int x, y;
};

GameObject player = {0, 0};
std::vector<GameObject> enemies;

void initGrid() {
    // Set empty spaces
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j] = '.';
        }
    }
    // Set trees
    for (int i = 0; i < NUM_TREES; ++i) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        grid[x][y] = 't';
    }
    // Set stones
    for (int i = 0; i < NUM_STONES; ++i) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        grid[x][y] = 's';
    }
    // Set player
    grid[player.x][player.y] = '@';
    // Set enemies
    for (int i = 0; i < NUM_ENEMIES; ++i) {
        GameObject enemy;
        do {
            enemy.x = rand() % GRID_SIZE;
            enemy.y = rand() % GRID_SIZE;
        } while (grid[enemy.x][enemy.y] != '.');
        enemies.push_back(enemy);
        grid[enemy.x][enemy.y] = 'e';
    }
}

void printGrid() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void movePlayer(char direction) {
    int newX = player.x;
    int newY = player.y;

    switch (direction) {
        case 'w': newX = player.x - 1; break;
        case 's': newX = player.x + 1; break;
        case 'a': newY = player.y - 1; break;
        case 'd': newY = player.y + 1; break;
    }

    // Check if the new position is within the grid and not blocked
    if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] == '.') {
        // Move player to the new position
        grid[player.x][player.y] = '.';
        player.x = newX;
        player.y = newY;
        grid[player.x][player.y] = '@';
    }
}

void moveEnemy(GameObject &enemy) {
    std::vector<std::pair<int, int>> possibleMoves = {
        {enemy.x - 1, enemy.y},
        {enemy.x + 1, enemy.y},
        {enemy.x, enemy.y - 1},
        {enemy.x, enemy.y + 1}
    };

    // Shuffle possible moves to randomize enemy direction
    std::random_shuffle(possibleMoves.begin(), possibleMoves.end());

    for (const auto &move : possibleMoves) {
        int newX = move.first;
        int newY = move.second;

        // Check if the new position is within the grid and not blocked
        if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] == '.') {
            // Move enemy to the new position
            grid[enemy.x][enemy.y] = '.';
            enemy.x = newX;
            enemy.y = newY;
            grid[enemy.x][enemy.y] = 'e';
            break; // Break after moving to avoid multiple moves
        }
    }
}

void moveEnemies() {
    for (GameObject &enemy : enemies) {
        moveEnemy(enemy);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    initGrid();
    printGrid();

    char input;
    int health = 10; // Player starts with 10 health points

    while (health > 0) {
        std::cout << "Move (w/a/s/d): ";
        std::cin >> input;

        // Ensure that the input is a valid move
        if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
            movePlayer(input);
            moveEnemies();

            // Check if any enemies are adjacent to the player
            for (const GameObject &enemy : enemies) {
                if (abs(player.x - enemy.x) <= 1 && abs(player.y - enemy.y) <= 1) {
                    health--; // Decrease health if enemy is adjacent
                    std::cout << "An enemy is close! Health is now: " << health << std::endl;
                }
            }

            printGrid();
        } else {
            std::cout << "Invalid move. Please use w, a, s, or d to move." << std::endl;
        }
    }

    std::cout << "Game over!" << std::endl;

    return 0;
}
