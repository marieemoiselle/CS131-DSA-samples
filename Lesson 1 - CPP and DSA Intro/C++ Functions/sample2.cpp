#include <iostream>
using namespace std;

void sampleFunction();
int addNumbers(int, int);

int main() {
  int sum = addNumbers(3, 5);
  sampleFunction(); 
  cout <<"addNumbers(3, 5): " << sum;
  // call the function
  return 0;
}

// create a function
void sampleFunction() {
  cout << "This is sampleFunction!\n";
}

int addNumbers(int x, int y){
  return x + y;
}

/*
    Output:
    This is sampleFunction!
    addNumbers(3, 5): 8
*/