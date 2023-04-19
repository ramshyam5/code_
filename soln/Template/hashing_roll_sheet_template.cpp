#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Node class template for linked list
template <class T>
class node {
public:
    T data;
    node<T> *next;

    node(T value) {
        data = value;
        next = NULL;
    }
};

// Singly Linked List class template
template <class T>
class sll {
private:
    node<T> *head;
public:
    sll() {
        head = NULL;
    }

    // Insert a new node at the beginning of the list
    void insert(T value) {
        node<T> *newNode = new node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Search for a node with the given value in the list
    bool search(T value) {
        node<T> *temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Print all the nodes in the list
    void print() {
        node<T> *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Hash class template using linked list
template <class T>
class HashTable {
private:
    int capacity;
    sll<T> *table;

    // Hash function to map key to index
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int size) {
        capacity = size;
        table = new sll<T>[capacity];
    }

    ~HashTable() {
        delete[] table;
    }

    // Insert a record into the hash table
    void insert(int key, T value) {
        int index = hashFunction(key);
        table[index].insert(value);
    }

    // Search for a record with the given key in the hash table
    bool search(int key, T value) {
        int index = hashFunction(key);
        return table[index].search(value);
    }

    // Print all the records in the hash table
    void print() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            table[i].print();
        }
    }
};

// String hash function using DJB2 algorithm
unsigned long hashFunction(string str) {
    unsigned long hash = 5381;
    for (char c : str) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

int main() {
    // Create a hash table of size 10
    HashTable<string> ht(10);

    // Read student records from a file and insert them into the hash table
    ifstream infile("CS Roll Sheet.txt");
    string line;
    while (getline(infile, line)) {
        // Extract the roll no and name from the line
        int pos = line.find(",");
        if (pos == string::npos) {
            cout << "Error: Invalid format in line - " << line << endl;
            continue;
        }
        string roll_str = line.substr(0, pos);
        string name = line.substr(pos + 1);

        // Convert roll_str to integer
        int roll;
        try {
            roll = stoi(roll_str);
        }
        catch (const invalid_argument& ia) {
            cout << "Error: Invalid roll no in line - " << line << endl;
            continue;
        }

        // Insert record into hash table
        ht.insert(roll, name);
    }

    // Search for a record in the hash table
    string search_roll_str;
    int search_roll;
    cout << "Enter the roll no to search: ";
    cin >> search_roll_str;
    try {
        search_roll = stoi(search_roll_str);
    }
    catch (const invalid_argument& ia) {
        cout << "Error: Invalid roll no entered" << endl;
        return 0;
    }
    bool found = ht.search(search_roll, "");
    if (found) {
        cout << "Record not found in the hash table" << endl;
    }
    else {
        cout << "Record found in the hash table" << endl;
    }
    cout<<"Name:PAWAN"<<" Reg NUM: 21U1096  category:OBC Roll no:21E80092"<<endl;

    return 0;
}
