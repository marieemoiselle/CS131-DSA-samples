/*
    C++ PROGRAM FOR LINKED LIST OPERATIONS
    Insertion
        - insert at beginning
        - insert after a node
        - insert at the end
    Deletion
        - deleting a node at a certain location
    Traverse
        - traverses the list
    Print
        - prints the list
*/

#include <iostream>
#include <string>
using namespace std;

// creating a node
struct Node {
    string data;
    struct Node* next;
};

// insert at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, string new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// insert node at the end of the linked list
void insertAtEnd(struct Node** head_ref, string new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// insert a node after a specified node
void insertAfter(struct Node* prev_node, string new_data) {
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL\n";
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// delete a node with a specified data value
void deleteNode(struct Node** head_ref, string key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

// Function to print the linked list
void printList(struct Node* node) {
    int index = 0;
    while (node != NULL) {
        cout << "[" << index << "]: " << node->data << endl;
        node = node->next;
        index++;
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice;
    string value;
    string position;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Delete a node\n";
        cout << "5. Print the list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character left in the buffer

switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning. Press 'x' to cancel:  ";
                getline(cin, value);
                if (value == "x") break;
                insertAtBeginning(&head, value);
                break;

            case 2:
                cout << "Enter value to insert at the end. Press 'x' to cancel: ";
                getline(cin, value);
                if (value == "x") break;
                insertAtEnd(&head, value);
                break;

            case 3:
                cout << "Enter value to insert after a node. Press 'x' to cancel: ";
                getline(cin, value);
                if (value == "x") break;
                cout << "Enter position to insert after. Press 'x' to cancel: ";
                getline(cin, position);
                if (position == "x") break;
                {
                    Node* temp = head;
                    while (temp != NULL && temp->data != position) {
                        temp = temp->next;
                    }
                    if (temp != NULL) {
                        insertAfter(temp, value);
                    } else {
                        cout << "Position data not found\n";
                    }
                }
                break;

            case 4:
                cout << "Enter value to delete. Press 'x' to cancel:  ";
                getline(cin, value);
                if (value == "x") break;
                deleteNode(&head, value);
                break;

            case 5:
                cout << "Current List:\n";
                printList(head);
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
                break;
        }
    }
}