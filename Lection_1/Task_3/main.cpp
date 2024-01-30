#include <iostream>

using namespace std;

int main()
{
    unsigned int height = 0;

    cout << "Enter height: ";
    cin >> height;

    for (unsigned int iteration = 0; iteration <= height; ++iteration) {
        unsigned int spaces;
        unsigned int asterisks;

        if (height == 0) {
            spaces = 0;
            asterisks = 1;
        } else if (iteration == height) {
            spaces = height - 1;
            asterisks = 1;
        } else {
            spaces = height - iteration - 1;
            asterisks = 1 + (iteration * 2);
        }

        while (spaces) {
            cout << " ";
            --spaces;
        }

        while (asterisks) {
            cout << "*";
            --asterisks;
        }

        cout << endl;
    }

    return 0;
}
