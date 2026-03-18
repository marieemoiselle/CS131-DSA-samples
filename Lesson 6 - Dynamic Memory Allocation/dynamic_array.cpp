#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "Array size: ";
    cin >> size;

    int* dynamicArray = new int[size];

    if (dynamicArray != nullptr) {
        for (int i = 0; i < size; i++) {
            dynamicArray[i] = i * 3;
        }

        for (int i = 0; i < size; i++) {
            cout << dynamicArray[i] << " ";
        }
        cout << endl;
        delete [] dynamicArray;
    }
    return 0;
}