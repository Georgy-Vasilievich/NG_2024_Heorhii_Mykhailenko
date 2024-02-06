#include <climits>
#include <iostream>

using namespace std;

int main()
{
    unsigned int size;
    cout << "Enter array size: ";
    cin >> size;

    int elements[size];
    int minimum = INT_MAX;
    int maximum = INT_MIN;

    for (unsigned int element = 0; element < size; ++element) {
        cout << "Enter element " << element << ": ";
        cin >> elements[element];

        if (elements[element] > maximum)
            maximum = elements[element];
        if (elements[element] < minimum)
            minimum = elements[element];
    }

    cout << "Maximum element: " << maximum << endl;
    cout << "Minimum element: " << minimum << endl;
    return 0;
}
