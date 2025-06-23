#include <iostream>
using namespace std;

struct Fraction{
    int numerator;
    int denominator;
};


// function declaration
void printFraction(Fraction);
// function for adding two fractions
Fraction addFractions(Fraction, Fraction);
int gcd(int, int);
Fraction simplify(Fraction);

int main(){

    Fraction fr1;
    fr1.numerator = 1;
    fr1.denominator = 2;
    Fraction fr2;
    fr2.numerator = 3;
    fr2.denominator = 4;

   Fraction total = addFractions(fr1, fr2);
    printFraction(fr1);
    cout<<" + ";
    printFraction(fr2);
    cout<<" = ";
    printFraction(total);

    return 0;
}

// function definitions
void printFraction(Fraction fr){
    // formal parameter
    cout<<fr.numerator <<"/" <<fr.denominator;
}

// definition for adding fractions
Fraction addFractions(Fraction fr1, Fraction fr2){
    Fraction sum;
    sum.numerator = fr1.numerator + fr2.numerator;
    sum.denominator = fr1.denominator + fr2.denominator;
    return simplify(sum);
}

int gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction simplify(Fraction f) {
    int common = gcd(f.numerator, f.denominator);
    f.numerator /= common;
    f.denominator /= common;
    return f;
}