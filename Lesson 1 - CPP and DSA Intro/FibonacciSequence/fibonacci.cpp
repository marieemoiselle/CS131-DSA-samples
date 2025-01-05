/*
    Generating the Fibonacci Sequence

    Step 1: Start
    Step 2: Declare an empty list = fib
    Step 3: Read n (number of terms in the Fibonacci Sequence)
    Step 4: If n <= 0
            Display "Invalid input" and stop
    Step 5: If n == 1
            Add 0 to fib and stop
    Step 6: Add 0 and 1 to fib
                Append 1 to fib
    Step 7: For each number from 2 to n-1, do the following:
            Calculate the next term as the sum of the last two numbers in fib
    Step 8: Add the next term to fib
    Step 9: Stop
            

*/

#include <iostream>
using namespace std;

int main() {
    int n;

    // Read the number of terms in the Fibonacci sequence
    cout << "Enter the number of terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    int first = 0, second = 1, nextTerm;

    // Handle the first term
    if (n >= 1) cout << first << " ";
    
    // Handle the second term
    if (n >= 2) cout << second << " ";

    // Generate the remaining terms
    for (int i = 3; i <= n; i++) {
        nextTerm = first + second;
        cout << nextTerm << " ";
        first = second;  // Update the first term
        second = nextTerm;  // Update the second term
    }

    cout << endl;

    return 0;
}
