#include <iostream>
using namespace std;

//structure of a node

struct Node {
    string data; //value
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

    head->data = "Fatima Marie";
    head->next = second;

    second->data = "Jei";
    second->next = third;

    third->data = "Renz Marrion";
    third->next = nullptr;

    // traversal and printing the linked list elements
    Node* current = head;
    /*while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }*/

    while (current != nullptr) {
        cout << current->data << " | " << current->next;
        if (current->next != nullptr)
            cout << " -> ";
        else
            cout << " -> nullptr";
        current = current->next;
    }

    return 0;
}