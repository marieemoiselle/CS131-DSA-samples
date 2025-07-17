#include <iostream>
using namespace std;

// size of the hash table
const int TABLE_SIZE = 10;

class HashTable {
    private:
        int table[TABLE_SIZE];
    
    public:
        HashTable() {
            // all slots shall be initialized to -1
            for (int i = 0; i < TABLE_SIZE; i++) {
                table[i] = -1;
            }
        }

        // simple hash function, using the key modulo table size
        int hashFunction(int key) {
            return key % TABLE_SIZE;
        }

        void insert(int key) {
            int index = hashFunction(key);

            // if slot is already taken
            // linear probing

            while (table[index] != -1) {
                index = (index + 1) % TABLE_SIZE;
            }

            table[index] = key;
            cout <<"Inserted " <<key <<" at position " << index <<"\n";
        }

        void display() {
            cout<<"\n------ HASH TABLE ------\n";
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout<<"[" << i << "] - ";
                if (table[i] == -1)
                    cout<<"{empty}\n";
                else
                    cout << table[i] <<endl;
            }
        }
};


int main() {
    HashTable ht;
    ht.insert(49);
    ht.insert(80);
    ht.insert(99);
    ht.insert(100);
    ht.insert(77);

    ht.display();

    return 0;
}