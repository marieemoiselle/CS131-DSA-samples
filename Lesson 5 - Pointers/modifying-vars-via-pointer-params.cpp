#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int x = 5;
	int y = 10;

	cout << "Before swap: x = " << x << ", y = " << y << endl;
	swap(&x, &y);
	cout << "After swap: x = " << x << ", y = " << y << endl;

	return 0;
}