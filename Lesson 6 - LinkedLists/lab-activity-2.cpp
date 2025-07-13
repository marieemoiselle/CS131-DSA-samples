#include <iostream>
#include <string>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    string data;
    Node* next;
};

// ----------- FUNCTION PROTOTYPES (just declarations) -----------
void insertAtBeginning(Node** head_ref, string new_data); 
void insertAtEnd(Node** head_ref, string new_data);
void insertAfterPosition(Node* head, int position, string new_data);
void deleteNodeByPosition(Node** head_ref, int position);
void printList(Node* node);

int main() {
    Node* head = nullptr;
    int choice;
    string value, positionInput;

    while (true) {  
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert after a position\n";
        cout << "4. Delete a node by position\n";
        cout << "5. Print the list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; 
        cin.ignore();

        switch (choice) {
            case 1:
                // insert at the beginning
                cout << "Enter value to insert at the beginning (or 'x' to cancel): ";
                getline(cin, value);
                if (value == "x") break;  // Cancel if 'x' is entered
                insertAtBeginning(&head, value); // Pass head pointer to the function
                break;

            case 2:
                // insert at the end
                cout << "Enter value to insert at the end (or 'x' to cancel): ";
                getline(cin, value);
                if (value == "x") break;
                insertAtEnd(&head, value);
                break;

            case 3:
                // insert after a certain position
                cout << "Enter new value to insert (or 'x' to cancel): ";
                getline(cin, value);
                if (value == "x") break;
                cout << "Insert after which position? (index starts at 0, or 'x' to cancel): ";
                getline(cin, positionInput);
                if (positionInput == "x") break;

                try {
                    int posIndex = stoi(positionInput); // Convert string to integer
                    insertAfterPosition(head, posIndex, value);
                } catch (...) {
                    cout << "Invalid input. Please enter a valid number.\n";
                }
                break;

            case 4:
                // delete node at a position
                cout << "Enter position to delete (index starts at 0, or 'x' to cancel): ";
                getline(cin, positionInput);
                if (positionInput == "x") break;

                try {
                    int posToDelete = stoi(positionInput); // Convert to integer
                    deleteNodeByPosition(&head, posToDelete);
                } catch (...) {
                    cout << "Invalid input. Please enter a valid number.\n";
                }
                break;

            case 5:
                // print entire list
                cout << "\nCurrent List:\n";
                printList(head);
                break;

            case 6:
                // exit loop and program
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}

// ------------------- Function Definitions ----------------------

// Inserts a node at the beginning of the list
void insertAtBeginning(Node** head_ref, string new_data) {
    Node* new_node = new Node();    // Create a new node in memory
    new_node->data = new_data;      // Store the data
    new_node->next = *head_ref;     // Point new node to the old head
    *head_ref = new_node;           // Update head to the new node
}

// Inserts a node at the end of the list
void insertAtEnd(Node** head_ref, string new_data) {
    Node* new_node = new Node();    // Create a new node
    new_node->data = new_data;      // Set its data
    new_node->next = nullptr;       // It'll be the last, so next is NULL

    if (*head_ref == nullptr) {     // If the list is empty
        *head_ref = new_node;       // Make new node the head
        return;
    }

    Node* last = *head_ref;         // Start from head
    while (last->next != nullptr) { // Go to the last node
        last = last->next;
    }

    last->next = new_node;          // Point last node to the new node
}

// Inserts a node after a given index/position
void insertAfterPosition(Node* head, int position, string new_data) {
    if (head == nullptr && position != 0) {
        cout << "List is empty. Cannot insert at that position.\n";
        return;
    }

    Node* temp = head;
    int index = 0;

    while (temp != nullptr && index < position) {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr) {
        cout << "Position index out of bounds.\n";
        return;
    }

    Node* new_node = new Node(); 
    new_node->data = new_data; 
    new_node->next = temp->next;
    temp->next = new_node;

    cout << "Inserted '" << new_data << "' after position " << position << ".\n";
}

// Deletes a node at a specific position/index
void deleteNodeByPosition(Node** head_ref, int position) {
    if (*head_ref == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = *head_ref;

    if (position == 0) {
        *head_ref = temp->next;
        delete temp;
        cout << "Deleted node at position 0.\n";
        return;
    }

    // Find the node before the one to delete
    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position index out of bounds.\n";
        return;
    }

    Node* nodeToDelete = temp->next; // Node to delete
    temp->next = nodeToDelete->next; // Skip the deleted node
    delete nodeToDelete;             // Free memory
    cout << "Deleted node at position " << position << ".\n";
}

// Prints all nodes in the list
void printList(Node* node) {
    if (node == nullptr) {     // If list is empty
        cout << "[Empty List]\n";
        return;
    }

    int index = 0;
    while (node != nullptr) {
        cout << "[" << index++ << "]: " << node->data << endl; // Show index and data
        node = node->next;
    }
}