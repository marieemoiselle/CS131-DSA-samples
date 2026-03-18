#include <iostream>
using namespace std;

int main() {
	int num = 10;
	int *ptr = &num;
	cout << "Value of num: " << *ptr << endl;
	cout << "Address of num: " << &num <<endl; 

	
	num = 25;
	cout << "Value of num: " << *ptr << endl;
	cout << "Address of num: " << ptr; 
	// Accessing the value through the pointer

	
	*ptr = 20;  
	// Modifying the value through the pointer
	cout << "\nUpdated value of num: " << *ptr << endl;
	cout << "Address of num: " << ptr;

	return 0;
}