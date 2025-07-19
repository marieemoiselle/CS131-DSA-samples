# LESSON 9: HASHING
CS 131 - Data Structures and Algorithms

Prepared by: **Ms. Fatima Marie P. Agdon, MSCS**.

## 🤔 What is Hashing?
Hashing is a technique used in data structures for efficient storage and retrieval of data, with quicker access. It is mainly used in implementing a set of distinct items (only keys) and dictionaries (key-value pairings).
- A **hash function** is used to map its data in a specific index to the hash table. That way, it will be faster to retrieve based on its key.
- Time complexity (search, insert, delete): ***O(1)***.

### 💥 Hash Collision
There are instances where hash functions return the same hash values for two or more keys. This scenario is known as **collision**. In order to handle such, we use the **collision resolution techniques**.

For this lesson, we will be using **Linear Probing**.

### 🔁 Linear Probing
Linear Probing is a collision resolution technique where the hash table is sequentially searched (starting from the original location of the hash), in cases where the location obtained is already occupied, the next location is checked.

***Algorithm***
1. Compute the index using: ```index = key % size```
2. If ```table[index]``` is empty:
   2.1. Store the key directly at ```table[index]```
3. If ```table[index]``` is occupied:
   3.1. Compute a new index: ```index = (index + 1) % size```
   3.2. Repeat Step 3 until an empty slot is found
4. Store the key at the empty index


## 🧪 Code Snippets
### A. For Integer Values
```cpp
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);

        // linear probing in case of collision
        int start = index; // to detect full table
        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
            if (index == start) {
                cout << "Hash table is FULL. Could not insert " << key << endl;
                return;
            }
        }

        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }
```

### B. For Strings
```cpp
int hashFunction(string key) {
    int hash = 0;
    for (char c : key) {
        hash += c;  // adds up ASCII values of each character
    }
    return hash % TABLE_SIZE;
}
```
How this works?
For example, you inputted the string: ```peach```. We will get the ASCII value of each character, get its sum, and use the hash function. Let's assume that the size of the hash table is ```10```.

So:

| character | ASCII Value |
|-----------|-------------|
|```p```| ```112```|
|```e```| ```101```|
|```a```| ```97```|
|```c```| ```99```|
|```h```| ```104```|
| Sum| ```513```|

```513 % 10 = 3```
Therefore, ```peach``` will be stored in location ```3```.

Just remember, the ASCII Code for ```a``` is: ```97```, ```A``` is ```65```, and ```0``` is ```48```.

## 💌 Acknowledgment
- Ma'am Lanie
- Ma'am Mace
- Ma'am Joy
- Ma'am Ria