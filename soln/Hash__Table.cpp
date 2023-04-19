#include <iostream>
#include <cstring>

using namespace std;

// Hash table using open addressing with linear probing
class HashTable {
private:
    int size;
    int *table;

    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int size) {
        this->size = size;
        table = new int[size];
        memset(table, -1, sizeof(int) * size);
    }

    void insert(int key) {
        int index = hash(key);
        int i = 0;

        while (table[index] != -1) {
            index = (index + 1) % size;
            i++;
            if (i == size) {
                cout << "Table is full!" << endl;
                return;
            }
        }

        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    int search(int key) {
        int index = hash(key);
        int i = 0;

        while (table[index] != -1) {
            if (table[index] == key) {
                cout << key << " found at index " << index << endl;
                return index;
            }
            index = (index + 1) % size;
            i++;
            if (i == size) {
                break;
            }
        }

        cout << key << " not found in table!" << endl;
        return -1;
    }

    void remove(int key) {
        int index = search(key);
        if (index == -1) {
            return;
        }

        table[index] = -1;
        cout << "Deleted " << key << " from index " << index << endl;

        index = (index + 1) % size;
        while (table[index] != -1) {
            int temp = table[index];
            table[index] = -1;
            insert(temp);
            index = (index + 1) % size;
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable table(10);
    table.insert(5);
    table.insert(12);
    table.insert(7);
    table.insert(10);
    table.insert(3);
    table.insert(9);
    table.insert(1);
    table.print();

    table.search(7);
    table.remove(7);
    table.print();

    return 0;
}
