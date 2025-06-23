#include <iostream>
using namespace std;

int main() {
    /*int arr[5] = {7, 14, 21, 28, 35};
    for(int idx = 0; idx < 5; idx++){
        cout<<arr[idx] <<" ";
    }*/


    int arr[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cout<<arr[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}