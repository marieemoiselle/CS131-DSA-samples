#include <iostream>
using namespace std;

void squareByReference(int* num) {
	*num = (*num) * (*num);
}

int main() {
	int num = 5;
	squareByReference(&num);

	cout << "Squared value: " << num << endl;
	return 0;
}