#include <iostream>
using namespace std;

int main() {

  int myNumbers[5] = {9, 18, 27, 36, 45};
  for (int i : myNumbers) {
    cout << i << " ";
  }
  
  return 0;
}

/*
    Output:
    9 18 27 36 45

*/