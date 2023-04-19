#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
    int size;
    vector<int> table;

    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return 7 - (key % 7);
    }

public:
    HashTable(int size) {
        this->size = size;
        table.resize(size, -1);
    }

    void insert(int key) {
        int index = hash1(key);
        int i = 0;
        while (table[index] != -1) {
            index = (hash1(key) + i * hash2(key)) % size;
            i++;
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hash1(key);
        int i = 0;
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (hash1(key) + i * hash2(key)) % size;
            i++;
        }
        return false;
    }

    void remove(int key) {
        int index = hash1(key);
        int i = 0;
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;
                return;
            }
            index = (hash1(key) + i * hash2(key)) % size;
            i++;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "] ";
            if (table[i] != -1) {
                cout << table[i];
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(10);

    ht.insert(5);
    ht.insert(25);
    ht.insert(12);
    ht.insert(42);
    ht.insert(33);

    cout << "Hash table:" << endl;
    ht.display();

    cout << "\nSearching for 25: " << (ht.search(25) ? "Found" : "Not found") << endl;
    cout << "Searching for 7: " << (ht.search(7) ? "Found" : "Not found") << endl;

    ht.remove(25);
    ht.remove(7);

    cout << "\nHash table after removals:" << endl;
    ht.display();

    return 0;
}
