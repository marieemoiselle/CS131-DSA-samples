/*
Step 1: Start
Step 2: Declare variables n, i, isPrime
Step 3: Initialize variable
    isPrime ← true
Step 4: Read n from the user
Step 5: If n ≤ 1, then
    isPrime ← false
    Go to Step 7
Step 6: Repeat steps while i = 2 to i * i ≤ n
    6.1 If remainder of n ÷ i equals 0, then
        isPrime ← false
        Exit the loop
Step 7: If isPrime = true, display n is a prime number
    Else display n is not a prime number
Step 8: Stop
*/

#include <iostream>
using namespace std;

int main () {
    int n;
    bool isPrime = true;

    cout << "Enter a number: ";
    cin >> n;

    if (n <= 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}