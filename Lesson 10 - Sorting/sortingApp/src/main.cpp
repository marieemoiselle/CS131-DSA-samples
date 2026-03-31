#include <iostream>
#include <limits>
#include "sorting.h"
#include "menu.h"
using namespace std;

int main() {
    
    cout << "\033[32m~ sorting algorithms ^^,\033[0m" << endl << endl;

    int n;

    do {
        cout << "enter number of array elements: ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            cout << "\033[31minvalid input! -.-\033[0m" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (n <= 0);

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "input element [" << i << "]: ";
            cin >> arr[i];
            if (cin.fail()) {
                cout << "\033[31minvalid input! -.-\033[0m" << endl;;
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            } else break;
        }
    }

    int choice = selectMenu();

    cout << "\nyou selected: ";
    switch (choice) {
        case 1: cout << "bubble sort ^o^\n"; bubbleSort(arr, n); break;
        case 2: cout << "insertion sort ^v^\n"; insertionSort(arr, n); break;
        case 3: cout << "selection sort ^u^\n"; selectionSort(arr, n); break;
        case 4: cout << "quick sort ^-^\n"; quickSort(arr, 0, n - 1, n); break;
        case 5: cout << "merge sort ^w^\n"; mergeSort(arr, 0, n - 1, n); break;
    }

    cout << "\n\033[32msorted array: \033[0m" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}