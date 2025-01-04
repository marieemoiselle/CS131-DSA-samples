#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* previous;
    Node* next;
};

// Create a doubly linked list: 1 <=> 2 <=> 3
int main() {
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 1;
    head->previous = nullptr;
    head->next = second;

    second->data = 2;
    second->previous = head;
    second->next = third;

    third->data = 3;
    third->previous = second;
    third->next = nullptr;

    // Traverse and print the elements of the linked list
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
