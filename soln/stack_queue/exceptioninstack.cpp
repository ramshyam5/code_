#include<bits/stdc++.h>
using namespace std;
template <class T>

class Stack{
    private:
    vector<T> data;
    public:
    void push(T elem){
        data.push_back(elem);
    }
    T pop();
    T top();
    bool empty(){
       return data.empty();
    }
    T size_ofstack(){
        return data.size();
    }
};
template <class T>
T Stack<T> :: pop(){
    if(data.empty()){
        throw out_of_range("Stack is empty");
    }
    T elem = data.back();
    data.pop_back();
    return elem;
}
template <class T>
T Stack<T> :: top(){
    if(data.empty()){
        throw out_of_range("Stack is empty");
    }
    return data.back();
}
int main(){
    
    try{
        Stack<int> intstack;
    intstack.push(1);
    intstack.push(2);
    intstack.push(3);
    while(!intstack.empty()){
        cout<<intstack.pop()<<endl;
    }
    cout<<intstack.pop()<<endl;
    }
    catch(exception&e){
        cerr<<"exception caught: "<<e.what()<<endl;
    }
    //cout<<intstack.pop()<<endl;
   
}