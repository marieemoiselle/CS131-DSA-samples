#include <iostream>
using namespace std;

int main() {
	int num = 10;
	int* ptr = &num;
	cout << "Value of num: " << *ptr << endl;  
	// Accessing the value through the pointer

	*ptr = 20;  
	// Modifying the value through the pointer
	cout << "Updated value of num: " << num << endl;

	return 0;
}