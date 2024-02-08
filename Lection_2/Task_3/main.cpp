#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;
    int maximum = 0;
    int isEven = -1;

    while (true) {
        int input = 0;
        std::cin >> input;

        if (input == 0)
            break;

        bool even = input % 2 == 0;

        if (isEven == -1)
            isEven = even;
        else if (isEven != even) {
            std::cout << "Need to only enter even or odd numbers." << std::endl;
            continue;
        }

        if (input > maximum)
            maximum = input;

        numbers.push_back(input);
    }

    for (auto& v : numbers) {
        for (int spaces = 0; spaces < (maximum - v) / 2; ++spaces)
            std::cout << " ";

        for (int asterisks = 0; asterisks < v; ++asterisks) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }


    return 0;
}
