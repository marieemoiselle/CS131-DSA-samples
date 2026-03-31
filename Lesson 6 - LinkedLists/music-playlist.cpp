#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* head = NULL;

// FUNCTIONS
void insert(string);
void display();

int main() {

    int n;
    string value;

    cout << "How many songs do you want to add? ";
    cin >> n;
    cin.ignore(); // para hindi masama yung newline sa getline

    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        getline(cin, value);
        insert(value);
    }

    cout << "\nYour Playlist:\n";
    display();

    return 0;
}

void insert(string s) {
    Node* newNode = new Node();
    newNode->data = s;
    newNode->next = NULL;

    // If empty
    if(head == NULL) {
        head = newNode;
    }
    // If not empty
    else {
        Node* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display() {
    Node* temp = head;

    if (head == NULL) {
        cout << "Empty list." << endl;
        return;
    }

    while (temp != NULL) {
        cout << "[" << temp->data << " | " << temp->next <<" ] -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}