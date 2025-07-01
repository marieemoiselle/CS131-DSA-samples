#include <iostream>
#include <string>
using namespace std;

// node structure
struct Node {
    string data;
    Node* next;
};

void appendNode (Node* &head, const string &value);
void displayList(Node *head);

int main() {
    Node* head = nullptr;
    string value;

    cout << "Enter strings to add to the list (type 'x' to stop):\n";
    
    while (true) {
        cout << "Enter data: ";
        getline(cin, value);

        if (value == "x") {
            break;
        }

        appendNode(head, value);
    }

    displayList(head);

    return 0;
}

// --- FUNCTION DEFINITIONS --- //
// function to add a new node at the end of the list
void appendNode(Node* &head, const string &value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// display linked list
void displayList(Node *head) {
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}