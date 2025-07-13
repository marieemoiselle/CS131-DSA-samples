#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    string data;
    Node* next;
};

// FUNCTION PROTOTYPES //
void insertAtBeginning(Node** head_ref, string new_data);
void insertAtEnd(Node** head_ref, string new_data);
void insertAfter(Node* prev_node, string new_data);
void deleteNode(Node** head_ref, string key);
void printList(Node* node);

// MAIN FUNCTION //
int main() {
    Node* head = nullptr;
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
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning (or 'x' to cancel): ";
                getline(cin, value);
                if (value == "x") break;
                insertAtBeginning(&head, value);
                break;

            case 2:
                cout << "Enter value to insert at the end (or 'x' to cancel): ";
                getline(cin, value);
                if (value == "x") break;
                insertAtEnd(&head, value);
                break;

            case 3:
                cout << "Enter new value to insert (or 'x' to cancel): ";
                getline(cin, value);
                if (value == "x") break;
                cout << "Insert after which position? (index starts at 0, or 'x' to cancel): ";
                getline(cin, position);
                if (position == "x") break;

                try {
                    int posIndex = stoi(position);
                    Node* temp = head;
                    int currentIndex = 0;

                    while (temp != nullptr && currentIndex < posIndex) {
                        temp = temp->next;
                        currentIndex++;
                    }

                    if (temp != nullptr) {
                        insertAfter(temp, value);
                    } else {
                        cout << "Position index out of bounds.\n";
                    }
                } catch (...) {
                    cout << "Invalid index input.\n";
                }
                break;

            case 4:
                cout << "Enter value to delete (or 'x' to cancel): ";
                getline(cin, value);
                if (value == "x") break;
                deleteNode(&head, value);
                break;

            case 5:
                cout << "\nCurrent List:\n";
                printList(head);
                break;

            case 6:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}

// FUNCTION DEFINITIONS //

void insertAtBeginning(Node** head_ref, string new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAtEnd(Node** head_ref, string new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
}

void insertAfter(Node* prev_node, string new_data) {
    if (prev_node == nullptr) {
        cout << "Cannot insert after a null node.\n";
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void deleteNode(Node** head_ref, string key) {
    Node* temp = *head_ref;
    Node* prev = nullptr;

    // if head needs to be deleted
    if (temp != nullptr && temp->data == key) {
        *head_ref = temp->next;
        delete temp;
        cout << "Node with value '" << key << "' deleted.\n";
        return;
    }

    // search for node
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // node not found
    if (temp == nullptr) {
        cout << "Node with value '" << key << "' not found.\n";
        return;
    }

    // remove the node
    prev->next = temp->next;
    delete temp;
    cout << "Node with value '" << key << "' deleted.\n";
}

// print the linked list
void printList(Node* node) {
    if (node == nullptr) {
        cout << "[Empty List]\n";
        return;
    }

    int index = 0;
    while (node != nullptr) {
        cout << "[" << index++ << "]: " << node->data << endl;
        node = node->next;
    }
}