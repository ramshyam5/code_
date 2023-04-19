#include<iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Hash table class
class HashTable {
private:
    Node** table;   // pointer to an array of linked lists
    int size;

    int hash(int key) {
        return key % size;   // simple hash function
    }

public:
    HashTable(int table_size) {
        size = table_size;
        table = new Node*[size];   // allocate array of linked lists
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;   // initialize all pointers to null
        }
    }

    ~HashTable() {
        // delete all nodes in each linked list
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] table;   // delete array of linked lists
    }

    void insert(int key) {
        int index = hash(key);
        Node* new_node = new Node(key);
        new_node->next = table[index];
        table[index] = new_node;
    }

    bool search(int key) {
        int index = hash(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data == key) {
                if (prev == nullptr) {
                    // first node in linked list
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

// Test the hash table
int main() {
    HashTable ht(10);
    ht.insert(12);
    ht.insert(23);
    ht.insert(34);
    ht.insert(45);
    ht.insert(56);
    ht.display();
    cout << "Search for 23: " << ht.search(23) << endl;
    cout << "Search for 99: " << ht.search(99) << endl;
    ht.remove(23);
    ht.display();
    return 0;
}
