#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Stack {
private:
    int data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int element) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        data[++top] = element;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1; // Return a sentinel value indicating error
        }
        return data[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1; // Return a sentinel value indicating error
        }
        return data[top];
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int n, element;

    cout << "Elements to push (Max: " << MAX_SIZE << "): ";
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "Limit: " << MAX_SIZE << " elements." << endl;
        n = MAX_SIZE;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter element #" << (i + 1) << ": ";
        cin >> element;
        stack.push(element);
    }

    cout << endl;
    stack.display();

    cout << "Pop: " << stack.pop() << endl;
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}