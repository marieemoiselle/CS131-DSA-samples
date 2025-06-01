#include <iostream>
using namespace std;

int findMissing(int arr[], int size){
    int total = (size + 1) * (size + 2)/2;
    int sum = 0;
    for (int idx = 0; idx < size; idx++){
        sum += arr[idx];
    }
    
    return total - sum;
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int *arr = new int[size];
    
    for(int idx = 0; idx < size; idx++){
        cout<<"Enter element: ";
        cin>>arr[idx];
    }
    
    int missing = findMissing(arr, size);
    cout<<"The missing number is: " <<missing;

    delete[]arr;
    
    return 0;
}