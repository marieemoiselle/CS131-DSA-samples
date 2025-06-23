#include <iostream>
using namespace std;

int main(){
    int x= 5, *ptr = &x;
    cout<<"Actual value of x: " <<x <<endl;
    cout<<"Actual value of ptr: " <<*ptr <<endl;
    cout<<"Value of ptr: " <<ptr <<endl;
    cout<<"Value of &x: " <<&x;
    return 0;
}