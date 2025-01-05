/*
    Finding the Factorial of a Number
    Step 1: START
    Step 2: Declare variables n, factorial and i.
    Step 3: Initialize variables
            factorial = 1
            i = 1
    Step 4: Read value of n
    Step 5: Repeat the steps until i = n
            5.1. factorial = factorial * i
            5.2. i = i + 1
    Step 6: Display factorial
    Step 7: STOP
*/

#include <iostream>
using namespace std;

int main(){
    int n, factorial = 1, i = 1;
    cout<< "Enter value for n: ";
    cin>> n;

    while(i <= n){
        factorial *= i; //factorial = factorial * i
        i++;
    }

    cout<<"Factorial: " << factorial;
    return 0;
}
