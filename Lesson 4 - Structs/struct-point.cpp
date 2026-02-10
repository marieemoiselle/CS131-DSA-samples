// Passing by value

#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
};

void modifyPointByValue(Point p) {
	p.x = 10;
	p.y = 20;
}

int main() {
	Point myPoint = {5, 5};
	modifyPointByValue(myPoint);

	cout << "Modified Point: x = " << myPoint.x << ", y = " << myPoint.y << endl;
	return 0;
}