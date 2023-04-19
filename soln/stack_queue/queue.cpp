/*Implement a queue class. You should have atleast these member functions:  initialize (construct), 
deconstruct, push, pop, display, isempty, isfull, etc. Show the use of the class by creating objects and calling the member functions.*/

#include<bits/stdc++.h>
using namespace std;
#define N 5
class Queue{
   int front,rear;
   int arr[N];
   public:
   void push(int);
   int pop();
   void display();
   int isempty();
   int isfull();
};


void Queue::push(int x){
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
        arr[rear]=x;
    }
    else{
        rear++;
        arr[rear]=x;
    }
}

int Queue::pop(){
    if(isempty()){
        cout<<"Queue_underflow"<<endl;
        exit(1);
    }
    int temp=arr[front];
    front++;
    return temp;
}

void Queue::display(){
    if(isempty()){
    cout<<"Queue underflow"<<endl;
    exit(1);
    }
    else {
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<endl;
        }
    }
}

int Queue::isempty(){
    if(rear==-1 || front==-1){
        return 1;
    }
    else return 0;
}

int Queue::isfull(){
    if(rear==N-1){
        return 1;
    }
    return 0;
}

int main(){
   
    Queue Q;
    int n;
  while(1){
     int choice ;
    cout<<"Enter choice "<<endl;
    cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.display"<<endl<<"4.isempty"<<endl<<"5.isfull"<<endl<<"6.exit"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1: cout<<"Enter element to push"<<endl;
        cin>>n;
        Q.push(n);
        break;

        case 2: cout<<"Popped element is "<<Q.pop()<<endl;
        break;
        case 3:Q.display();
        break;
        case 4:Q.isempty();
        break;
        case 5:Q.isfull();
        break;
        case 6:exit(1);
    }
  }
}