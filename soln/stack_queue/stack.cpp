/*Implement a stack class. You should have atleast these member functions:  initialize (construct), 
deconstruct, push, pop, display, isempty, isfull, etc. Show the use of the class by creating objects and calling the member functions.*/
#include<bits/stdc++.h>
using namespace std;
#define N 4

class Stack{
   int top;
   int size;
   int arr[N];
   public:
   Stack(){
    top=-1;
     
   }
   void push(int);
   void pop();
   int top_();
   int isempty();
   int isfull();
   void display();
   ~Stack(){
     cout<<"Destructor is called"<<endl;
   }
};


void Stack::push(int x){
    if(isfull()){
        cout<<"Stack is overflow"<<endl;
        exit(1);
    }
    top++;
    arr[top]=x;
}

void Stack::pop(){
    if(isempty()){
        cout<<"Stack is underflow"<<endl;
        exit(1);
    }
    else {
        top--;
    }
}

int Stack::top_(){
    return arr[top];
}

int Stack::isempty(){
    if(top==-1){
        return 1;
    }
    else return 0;
}


int Stack::isfull(){
    if(top==N-1){
        return 1;
    }
    else return 0;
}

void Stack::display(){
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Stack st;
    int ele,n;

    while(1){
        cout<<"Enter your choice"<<endl;
        cout<<"1.Push"<<endl<<"2.pop"<<endl<<"3.top"<<endl<<"4.display"<<endl<<"5.exit"<<endl;
        cin>>n;
        if(n==1){
            cout<<"Enter element to push in stack "<<endl;
            cin>>ele;
            st.push(ele);
        }
        else if(n==2){
            st.pop();
        }
        else if(n==3){
            cout<<"Top element in stack is "<<st.top_();
        }
        else if(n==4){
            cout<<"Displaying stack elements "<<endl;
            st.display();
        }
        else if(n==5){
            break;
        }
        else {
            cout<<"Wrong choice "<<endl;
        }
    }
}