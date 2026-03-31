#include <iostream>
#include <iomanip>
#include "sorting.h"
using namespace std;

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << setw(4) << arr[i] << " ";
    cout << endl;
}