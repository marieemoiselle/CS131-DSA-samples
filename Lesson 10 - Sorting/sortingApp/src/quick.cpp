#include <iostream>
#include "sorting.h"
using namespace std;

static bool firstQuick = true;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int size) {
    if (firstQuick) {
        cout << "\033[36minitial array:\033[0m" << endl;
        display(arr, size);
        firstQuick = false;
    }

    if (low < high) {
        int pi = partition(arr, low, high);
        display(arr, size); // always display full array
        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
    }
}