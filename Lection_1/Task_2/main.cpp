#include <iostream>

using namespace std;

int main()
{
    int income = 0;

    cout << "How much do you earn? ";
    cin >> income;

    if (income < 1000) {
        cout << "Work more";
    }

    if (income > 1000) {
        if (income < 1000000) {
            cout << "Good job";
        }

        if (income > 1000000) {
            cout << "You are a millionaire";
        }
    }

    cout << ", well done!" << endl;

    return 0;
}
