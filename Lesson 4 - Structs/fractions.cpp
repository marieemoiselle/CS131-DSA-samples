#include <iostream>
using namespace std;

struct Fraction{
    int numerator;
    int denominator;
};


// function declaration
void printFraction(Fraction);
// function for adding two fractions

int main(){

    Fraction fr1;
    fr1.numerator = 1;
    fr1.denominator = 2;
    printFraction(fr1);

    Fraction fr2;
    fr2.numerator = 3;
    fr2.denominator = 4;
    printFraction(fr2);
    
    return 0;
}

// function definitions
void printFraction(Fraction fr){
    // formal parameter
    cout<<fr.numerator <<"/" <<fr.denominator <<endl;
}

// definition for adding fractions