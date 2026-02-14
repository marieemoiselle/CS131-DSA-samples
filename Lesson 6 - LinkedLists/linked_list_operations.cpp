#include <iostream>
using namespace std;

// Node - implemented as a struct
struct Node {
    int data;       // this will hold integer values
    Node* next;     // pointer to next node
};

/* FUNCTION DECLARATIONS */
void display(Node* head);                   // 1. Traverse/display

void insertFirst(Node*& head, int value);  // 2. insert at head node
void insertEnd(Node*& head, int value);    // 3. insert at last
void insertAfter(Node* head, int target, int value);  // 4. insert after a node
void insertBefore(Node*& head, int target, int value); // 5. insert before a node

bool search(Node* head, int value);   // 6. search an element

void deleteFirst(Node*& head);     // 7. delete first node
void deleteEnd(Node*& head);       // 8. delete last node
void deleteValue(Node*& head, int value);   // 9. delete a certain node

/* main() FUNCTION */
int main() {
    Node* head = nullptr;

    insertFirst(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    display(head);

    insertAfter(head, 20, 25);
    insertBefore(head, 10, 5);

    display(head);

    cout << "Search 25: ";
    cout << (search(head, 25) ? "Found" : "Not Found") << endl;

    deleteFirst(head);
    deleteEnd(head);
    deleteValue(head, 20);

    display(head);

    return 0;
}

/* FUNCTION DEFINITIONS */

// 1. Display/Traverse
void display(Node* head) {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 2. Insert at Head Node
void insertFirst(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// 3. Insert at Last Position
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// 4. Insert after a node
void insertAfter(Node* head, int target, int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != target)
        temp = temp->next;

    if (temp == nullptr) return;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// 5. Insert before a node
void insertBefore(Node*& head, int target, int value) {
    if (head == nullptr) return;

    if (head->data == target) {
        insertFirst(head, value);
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr && curr->data != target) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) return;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = curr;
    prev->next = newNode;
}

// 6. Search for an element
bool search(Node* head, int value) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

// 7. Delete head node
void deleteFirst(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// 8. Delete end node
void deleteEnd(Node*& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

// 9. Delete specific value
void deleteValue(Node*& head, int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        deleteFirst(head);
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) return;

    prev->next = curr->next;
    delete curr;
}