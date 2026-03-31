#include <iostream>
#include "sorting.h"
using namespace std;

void insertionSort(int arr[], int n) {
    cout << "\033[36minitial array:\033[0m" << endl;
    display(arr, n);

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        display(arr, n);
    }
}