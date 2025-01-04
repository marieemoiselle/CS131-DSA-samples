#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
	Node* front;
	Node* rear;

public:
	Queue() : front(nullptr), rear(nullptr) {}

	void enqueue(int element) {
		Node* newNode = new Node(element);

		if (front == nullptr) {
			front = newNode;
			rear = newNode;
		} else {
			rear->next = newNode;
			rear = newNode;
		}
	}

	int dequeue() {
		if (front == nullptr) {
			cout << "Queue Underflow" << endl;
			return -1; // Return a sentinel value indicating error
		}

		Node* temp = front;
		int data = temp->data;

		front = front->next;

		if (front == nullptr) {
			rear = nullptr;
		}

		delete temp;
		return data;
	}

	int peek() {
		if (front == nullptr) {
			cout << "Queue is empty" <<endl;
			return -1; // Return a sentinel value indicating error
		}
		return front->data;
	}
};

int main() {
	Queue queue;

	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);

	cout << "Peek: " << queue.peek() << endl;
	cout << "Dequeue: " << queue.dequeue() <<endl;
	cout << "Peek: " << queue.peek() << endl;

	return 0;
}
