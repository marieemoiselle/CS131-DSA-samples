#include <iostream>
#include "sorting.h"
using namespace std;

void selectionSort(int arr[], int n) {
    cout << "\033[36minitial array:\033[0m" << endl;
    display(arr, n);

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swap(arr[i], arr[minIndex]);

        display(arr, n);
    }
}