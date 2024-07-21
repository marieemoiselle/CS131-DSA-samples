#include <iostream>
using namespace std;

//structure of a node

struct Node {
    int data; //value
    Node* next; //pointer to the next value
};

// creating a single linked list with node values 1 2 and 3
int main() {
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    // traversal and printing the linked list elements
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}