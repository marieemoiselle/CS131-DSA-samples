#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    string table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = "";  // empty string = empty slot
        }
    }

    // hash function for strings
    int hashFunction(string key) {
        int hash = 0;
        for (char c : key) {
            hash += c;  // sum of ASCII values
        }
        return hash % TABLE_SIZE;
    }

    void insert(string key) {
        int index = hashFunction(key);
        int start = index;  // to detect full loop

        while (table[index] != "") {
            index = (index + 1) % TABLE_SIZE;
            if (index == start) {
                cout << "Hash table is FULL. Could not insert \"" << key << "\".\n";
                return;
            }
        }

        table[index] = key;
        cout << "Inserted \"" << key << "\" at index " << index << endl;
    }

    void display() {
        cout << "\n----- HASH TABLE -----   \n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            if (table[i] == "")
                cout << "{empty}" << endl;
            else
                cout << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht;
    int n;
    string input;

    cout << "----- Hash Table for Strings via Linear Probing -----\n";
    cout << "Enter number of strings to insert: ";
    cin >> n;

    cin.ignore(); // Clear newline left by previous input

    for (int i = 0; i < n; i++) {
        cout << "Enter string #" << (i + 1) << ": ";
        getline(cin, input);
        ht.insert(input);
    }

    ht.display();

    return 0;
}