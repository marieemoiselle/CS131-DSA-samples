#include <iostream>
#include "sorting.h"
using namespace std;

void bubbleSort(int arr[], int n) {
    cout << "\033[36minitial array:\033[0m" << endl;
    display(arr, n);

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped) display(arr, n);
    }
}