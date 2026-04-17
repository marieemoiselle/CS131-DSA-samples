#include <iostream>
using namespace std;

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main() {
    int size;

    cout << "Enter array size: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int target;
    cout << "\nEnter value to search: ";
    cin >> target;

    bool found = false;

    cout << "\n---" << YELLOW << " Linear Searching " << RESET << " ---\n";

    for (int i = 0; i < size; i++) {
        cout << "Step " << i + 1 << ": INDEX " << i 
             << " (value = " << arr[i] << ")";

        if (arr[i] == target) {
            cout << " --> " << GREEN << "ELEMENT FOUND\n" << RESET;
            found = true;
        } else {
            cout << " --> not match\n";
        }
    }

    // Display results
    if (found) {
        cout << "\nElement " << target << " found at indices: ";
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                cout << i << " ";
            }
        }
        cout << endl;
    } else {
        cout << RED << "\nElement not found.\n" << RESET;
    }

    return 0;
}