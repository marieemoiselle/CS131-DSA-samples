#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    int numbers[5] = {4, 8, 12, 16};
    int size = sizeof(numbers) / sizeof(int);
    
    cout << "Base Address: " << numbers << endl;

    for (int i = 0; i < size; i++) {
        cout << "numbers [" << i << "] = " 
        << setw(3) << numbers[i] 
        << " | address: " << &numbers[i] << endl;
    }
return 0;
}