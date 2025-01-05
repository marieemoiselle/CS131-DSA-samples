#include <iostream>
using namespace std;

int getFactorial(int);

int main() {
    int n, result;

    cout << "Enter a non-negative number: ";
    cin >> n;

    result = getFactorial(n);
    cout << "Factorial of " << n << " = " << result;
    return 0;
}

int getFactorial(int n) {
    if (n > 1) {
        return n * getFactorial(n - 1);
    } else {
        return 1;
    }
}