#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert at end
void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    // if list is empty
    if (head == nullptr) {
        head = newNode;
        newNode->next = head; // points to itself
        return;
    }

    Node* temp = head;

    // move to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head; // circular link
}

// Display circular linked list
void display(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)" << endl;
}

int main() {
    Node* head = nullptr;

    insert(head, 9);
    insert(head, 18);
    insert(head, 27);

    cout << "Circular Linked List: ";
    display(head);

    return 0;
}