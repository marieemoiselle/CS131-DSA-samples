#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 4;
    int z = 12;
    int w = 11;

    cout << x + y << endl;      // 14
    cout << x - y << endl;      // 6
    cout << x * y << endl;      // 40
    cout << x / y << endl;      // 2
    cout << x % y << endl;      // 2
    cout << x++ << endl;        // 10 - post-increment
    cout << ++z << endl;        // 13 - pre-increment
    cout << y-- << endl;        // 4 - post-decrement
    cout << --w << endl;        // 10 - pre-decrement

    return 0;
}