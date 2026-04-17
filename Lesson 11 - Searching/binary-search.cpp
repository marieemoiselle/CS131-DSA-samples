#include <iostream>
using namespace std;

// function declarations //
void sortArray(int[], int);
int binarySearch(int[], int, int);
void findAllOccurrences(int[], int, int, int);

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

    // call the sorting function
    sortArray(arr, size);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    int target;
    cout << "\n\nEnter value to search: ";
    cin >> target;

    int index = binarySearch(arr, size, target);

    // function to handle all duplicates
    findAllOccurrences(arr, size, index, target);

    return 0;
}

// Function to sort array (selection sort)
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// binary searching including the step ny step display
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int step = 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        // for the display
        cout << "\n\033[36mSTEP " << step++ << ":\033[0m\n";
        cout << "LEFT = " << left << ", RIGHT = " << right << ", MID = " << mid << endl;
        cout << "arr[" << mid << "] = " << arr[mid] << endl;

        if (arr[mid] == target) {
            return mid; // found one occurrence
        }
        else if (arr[mid] < target) {
            cout << "Move RIGHT\n";
            left = mid + 1;
        }
        else {
            cout << "Move LEFT\n";
            right = mid - 1;
        }
    }

    return -1;
}

// function to find occurrences/duplicates
void findAllOccurrences(int arr[], int size, int index, int target) {
    if (index == -1) {
        cout << "Element not found.\n";
        return;
    }

    cout << "\nElement " << target << " found!" << endl;

    // trace the left side
    int i = index;
    while (i >= 0 && arr[i] == target) {
        i--;
    }

    // trace the right side
    int j = index;
    while (j < size && arr[j] == target) {
        j++;
    }

    cout << "Element " << target << " found at indices: ";
    for (int k = i + 1; k < j; k++) {
        cout << k << " ";
    }
    cout << endl;
}