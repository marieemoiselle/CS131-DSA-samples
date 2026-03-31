#include <iostream>
#include <limits>
using namespace std;

// FUNCTION PROTOTYPES
void display(int[], int);
int select();
void bubbleSort(int[], int);
void insertionSort(int[], int);
void selectionSort(int[], int);
void quickSort(int[], int, int);
int partition(int[], int, int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);

// MAIN FUNCTION (METHOD CALLS ONLY)
int main() {
    int n;

    // Input validation for size
    do {
        cout << "How many elements? : ";
        cin >> n;

        if (cin.fail() || n <= 0) {
            cout << "Invalid input. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (n <= 0);

    int* arr = new int[n];

    // Input elements with validation
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "Input element [" << i << "]: ";
            cin >> arr[i];

            if (cin.fail()) {
                cout << "Invalid input. Enter an integer.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else break;
        }

       // delete[] arr;
    }

    int choice = select();

    cout << "\nYou selected - ";

    switch (choice) {
        case 1:
            cout << "Bubble Sort\n\nBubble Sort:\n";
            bubbleSort(arr, n);
            break;
        case 2:
            cout << "Insertion Sort\n\nInsertion Sort:\n";
            insertionSort(arr, n);
            break;
        case 3:
            cout << "Selection Sort\n\nSelection Sort:\n";
            selectionSort(arr, n);
            break;
        case 4:
            cout << "Quick Sort\n\nQuick Sort:\n";
            quickSort(arr, 0, n - 1);
            break;
        case 5:
            cout << "Merge Sort\n\nMerge Sort:\n";
            mergeSort(arr, 0, n - 1);
            break;
    }

    // Final sorted array
    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }

    cout << endl;
    return 0;
}

// FUNCTION DEFINITIONS

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// MENU SELECTION FUNCTION
int select() {
    int choice;

    do {
        cout << "\nWhich sorting algorithm?\n";
        cout << "1 - Bubble\n2 - Insertion\n3 - Selection\n4 - Quick\n5 - Merge\n";
        cout << "\nYour choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cout << "Invalid choice. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice < 1 || choice > 5);

    return choice;
}

// BUBBLE SORT
void bubbleSort(int arr[], int n) {
    display(arr, n);

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped)
            display(arr, n);
    }
}

// INSERTION SORT
void insertionSort(int arr[], int n) {
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

// SELECTION SORT
void selectionSort(int arr[], int n) {
    display(arr, n);

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }

        display(arr, n);
    }
}

// QUICK SORT
void quickSort(int arr[], int low, int high) {
    static bool first = true;
    if (first) {
        display(arr, high + 1);
        first = false;
    }

    if (low < high) {
        int pi = partition(arr, low, high);
        display(arr, high + 1);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// PARTITION
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

// MERGE SORT
void mergeSort(int arr[], int left, int right) {
    static bool first = true;
    if (first) {
        display(arr, right + 1);
        first = false;
    }

    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);

        display(arr, right + 1);
    }
}

// MERGE FUNCTION
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L =  new int[n1];
    int* R =  new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}