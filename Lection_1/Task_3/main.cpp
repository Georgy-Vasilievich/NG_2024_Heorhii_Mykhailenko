#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main() {
    unsigned int height;

    cout << "Enter height: ";
    cin >> height;

    if (height > 0) {
        for (unsigned int iteration = 0; iteration < height; ++iteration) {
            for (unsigned int spaces = 0; spaces < height - iteration - 1; ++spaces) {
                cout << " ";
            }

            for (unsigned int asterisks = 0; asterisks < (2 * iteration + 1); ++asterisks) {
                cout << "*";
            }
            cout << endl;
        }

        for (unsigned int spaces = 0; spaces < height - 1; ++spaces) {
            cout << " ";
        }
    }

    cout << "*" << endl;

    return 0;
}
