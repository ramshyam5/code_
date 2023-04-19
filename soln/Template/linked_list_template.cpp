#include <iostream>
#include <string>
#include <complex>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}
    void insert(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }
    void printList() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

struct Student {
    string name;
    string rollNo;
    int year;
    char gender;
    float cgpa;
    string regnNo;
};

ostream& operator<<(ostream& os, const Student& s) {
    os << "Name: " << s.name << ", Roll No.: " << s.rollNo
       << ", Year: " << s.year << ", Gender: " << s.gender
       << ", CGPA: " << s.cgpa << ", Regn No.: " << s.regnNo;
    return os;
}

int main() {
    LinkedList<int> intList;
    intList.insert(5);
    intList.insert(10);
    intList.insert(15);
    intList.printList();

    LinkedList<char> charList;
    charList.insert('a');
    charList.insert('b');
    charList.insert('c');
    charList.printList();

    LinkedList<float> floatList;
    floatList.insert(3.14);
    floatList.insert(2.718);
    floatList.insert(1.618);
    floatList.printList();

    LinkedList<complex<double>> complexList;
    complexList.insert(complex<double>(1.0, 2.0));
    complexList.insert(complex<double>(3.0, 4.0));
    complexList.printList();

    LinkedList<Student> studentList;
    studentList.insert({"Surav Raj", "123456", 2022, 'M', 3.5, "789012"});
    studentList.insert({"Jane Smith", "654321", 2023, 'F', 3.9, "210987"});
    studentList.printList();

    return 0;
}
