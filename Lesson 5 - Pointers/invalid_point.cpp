#include <iostream>
using namespace std;

int main () {

    int x = 10;
    float* ptr = &x;

    cout << "Pointer to x: " << ptr;

    return 0;
}