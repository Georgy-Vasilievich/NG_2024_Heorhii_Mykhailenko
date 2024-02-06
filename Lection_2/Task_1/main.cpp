#include <iostream>

using namespace std;

int main()
{
    unsigned int size;
    cout << "Enter array size: ";
    cin >> size;

    int elements[size];
    int sumEven = 0;
    int sumOdd = 0;

    for (unsigned int element = 0; element < size; ++element) {
        cout << "Enter element " << element << ": ";
        cin >> elements[element];

        if (element % 2 == 0)
            sumEven += elements[element];
        else
            sumOdd += elements[element];
    }

    cout << "Total sum: " << sumEven + sumOdd << endl;
    cout << "Even sum: " << sumEven << endl;
    cout << "Odd sum: " << sumOdd << endl;

    return 0;
}
