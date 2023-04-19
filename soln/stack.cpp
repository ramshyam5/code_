#include <iostream>
#include <vector>
#include<complex>

using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> data; // underlying container

public:
    // push an element onto the stack
    void push(const T &elem)
    {
        data.push_back(elem);
    }

    // remove and return the top element from the stack
    T pop()
    {
        if (data.empty())
        {
            throw out_of_range("Stack is empty");
        }
        T elem = data.back();
        data.pop_back();
        return elem;
    }

    // return the top element of the stack without removing it
    T &top()
    {
        if (data.empty())
        {
            throw out_of_range("Stack is empty");
        }
        return data.back();
    }

    // check if the stack is empty
    bool empty() const
    {
        return data.empty();
    }

    // return the number of elements in the stack
    size_t size() const
    {
        return data.size();
    }
};

// Example usage of the Stack class template
int main()
{
    Stack<int> int_stack;
    int_stack.push(1);
    int_stack.push(2);
    cout << int_stack.pop() << endl; // output: 2

    Stack<char> char_stack;
    char_stack.push('a');
    char_stack.push('b');
    cout << char_stack.top() << endl; // output: b

    Stack<float> float_stack;
    float_stack.push(3.14);
    float_stack.push(2.718);
    cout << float_stack.pop() << endl; // output: 2.718

    Stack<complex<double>> complex_stack;
    complex_stack.push(complex<double>(1.0, 2.0));
    complex_stack.push(complex<double>(3.0, 4.0));
    cout << complex_stack.top() << endl; // output: (3,4)

    struct Student
    {
        string name;
        string roll_no;
        int year;
        char gender;
        float CGPA;
        string reg_no;
    };
    Stack<Student> student_stack;
    student_stack.push({"Alice", "18CS001", 2022, 'F', 8.5, "REG001"});
    student_stack.push({"Bob", "18CS002", 2022, 'M', 9.0, "REG002"});
    cout << student_stack.pop().name << endl; // output: Bob
    cout << student_stack.pop().roll_no << endl; 
  

    return 0;
}
