/*
    Getting the Largest Value

    Step 1: Start
    Step 2: Declare variables a, b, and c.
    Step 3: Read variables a, b, and c.
    Step 4: If a > b
                If a > c
                    Display a is the largest number
                Else
                    Display c is the largest number
            Else
                If b > c
                    Display b is the largest number
                Else 
                    Display c is the greatest number
    Step 5: Stop

*/

#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cout <<"Enter value for a: ";
    cin >>a;
    cout <<"Enter value for b: ";
    cin >>b;
    cout <<"Enter value for c: ";
    cin >>c;
    
    if (a > b){
        if (a > c){
            cout <<a <<" is the greatest number";
        }
        else {
            cout <<c <<" is the greatest number"; 
        }
    }
    else if (b > c) {
        if (b > c){
            cout <<b <<" is the greatest number";
        }
        else {
            cout <<c <<" is the greatest number"; 
        }
    }
    
    return 0;
}