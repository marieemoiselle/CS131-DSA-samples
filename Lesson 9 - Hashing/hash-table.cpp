#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    int table[TABLE_SIZE];
    int count; // track number of inserted elements

public:
    HashTable() {
        count = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    // hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {

        // check if table is full
        if (count == TABLE_SIZE) {
            cout << "Hash Table is FULL! Cannot insert " << key << endl;
            return;
        }

        int index = hashFunction(key);

        // linear probing
        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }

        table[index] = key;
        count++;

        cout << "Inserted " << key << " at position " << index << endl;
    }

    void display() {
        cout << "\n----- HASH TABLE -----\n";

        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "[" << i << "] - ";

            if (table[i] == -1)
                cout << "{empty}" << endl;
            else
                cout << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(49);
    // 49 % 10 = 9
    ht.insert(80);
    // 80 % 10 = 0
    ht.insert(99);
    // 99 % 10 = 9 - collision - linear probing - index 1
    ht.insert(100);
    // 100 % 10 = 0 - collision - linear probing - index 2
    ht.insert (77);
    // 77 % 10 = 7 

    ht.display();

    return 0;
}

/* 

Insert element 34 into the hash table
Hash Function: key % TABLE_SIZE
TABLE_SIZE = 10
34 % 10 = 4
Insert 74
74 % 10 = 4 // collision
Insert 55
55 % 10 = 5 // collision

==== HASH TABLE ====
[0]
[1]
[2]
[3]
[4] - 34
[5] - 74
[6] - 55
[7]
[8]
[9]

*/