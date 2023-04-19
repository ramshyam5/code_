#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    int *table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable() {
        size = TABLE_SIZE;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;  // -1 indicates empty slot
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i) % size] != -1) {
            i++;
            if (i == size) {
                cout << "Hash table is full" << endl;
                return;
            }
        }
        table[(index + i) % size] = key;
        cout << "Inserted key " << key << " at index " << (index + i) % size << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i) % size] != key) {
            i++;
            if (table[(index + i) % size] == -1 || i == size) {
                cout << "Key not found" << endl;
                return;
            }
        }
        cout << "Key found at index " << (index + i) % size << endl;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i) % size] != key) {
            i++;
            if (table[(index + i) % size] == -1 || i == size) {
                cout << "Key not found" << endl;
                return;
            }
        }
        table[(index + i) % size] = -1;
        cout << "Removed key " << key << " from index " << (index + i) % size << endl;
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; i++) {
            if (table[i] == -1) {
                cout << i << ": Empty" << endl;
            } else {
                cout << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(3);
    ht.insert(7);
    ht.insert(17);
    ht.insert(22);
    ht.insert(30);
    ht.insert(35);
    ht.display();

    ht.search(22);
    ht.search(8);

    ht.remove(17);
    ht.remove(8);

    ht.display();

    return 0;
}