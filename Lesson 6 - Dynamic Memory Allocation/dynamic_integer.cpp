#include <iostream>
using namespace std;

int main() {
    int* dynamicInt = new int;

    if (dynamicInt != nullptr) {
        *dynamicInt = 42;
        cout << "Value: " << dynamicInt << endl;
        delete dynamicInt;
    }
    return 0;

    // Value: 42
}