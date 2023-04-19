#include <iostream>
#include <vector>
#include <exception>

using namespace std;

template<typename T>
class Stack {
private:
    vector<T> elements;
public:
    void push(const T& value) {
        elements.push_back(value);
    }
    
    T pop() {
        if (elements.empty()) {
            throw underflow_error("Stack is empty");
        }
        T last_element = elements.back();
        elements.pop_back();
        return last_element;
    }
    
    T top() {
        if (elements.empty()) {
            throw underflow_error("Stack is empty");
        }
        return elements.back();
    }
    
    bool empty() const {
        return elements.empty();
    }
};

int main() {
    try {
        Stack<int> int_stack;
        int_stack.push(1);
        int_stack.push(2);
        int_stack.push(3);
        cout << int_stack.top() << endl; // output: 3
        int_stack.pop();
        cout << int_stack.top() << endl; // output: 2
        int_stack.pop();
        cout << int_stack.top() << endl; // output: 1
        int_stack.pop();
        cout << int_stack.top() << endl; // throws an exception
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }
    
    return 0;
}
