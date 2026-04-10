#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// function prototypes
void insert(int);
void display();

int main() {

    cout << "Linked List before inserting elements:" << endl;
    display();

    insert(9);
    insert(18);
    insert (27);

    cout << "Linked List after inserting elements:" << endl;
    display();

    return 0;
}

void insert(int value) {
    Node* newNode = new Node();
     newNode->data = value; // assigns the node
     newNode->next = NULL; // since it is the last node

     if (head == NULL) {
        head = newNode;
     }

     else {
        Node *temp = head;
        while (temp->next != NULL) {
            // If there is still a node after it
            temp = temp->next;
        }
        temp->next = newNode;
     }
}

void display() {
    Node* temp = head;

    if(temp == NULL) {
        cout << "List is empty." << endl;
        return; // end of function
    }

    while (temp != NULL) {
        cout << "[ " << temp->data <<" | " << temp->next << "] -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;

}