#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Queue {
private:
	int data[MAX_SIZE];
	int front;
	int rear;

public:
	Queue() : front(0), rear(-1) {}

	void enqueue(int element) {
		if (rear == MAX_SIZE - 1) {
			cout << "Queue Overflow" <<endl;
			return;
		}
		data[++rear] = element;
	}

	int dequeue() {
		if (front > rear) {
			cout << "Queue Underflow" <<endl;
			return -1; // Return a sentinel value indicating error
		}
		return data[front++];
	}

	int peek() {
		if (front > rear) {
			cout << "Queue is empty" <<endl;
			return -1; // Return a sentinel value indicating error
		}
		return data[front];
	}
};

int main() {
	Queue queue;

	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.dequeue();
	queue.peek();

	cout << "Peek: " << queue.peek() <<endl;
	cout << "Dequeue: " << queue.dequeue() <<endl;
	cout << "Peek: " << queue.peek() <<endl;

	return 0;
}
