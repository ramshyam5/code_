/*Impelement a Code to execute Overload ++ when used as prefix and postfix.*/

#include<bits/stdc++.h>
using namespace std;

class Weight{
    public:
    int kg;
    Weight(){
        kg=0;
    }
    Weight(int x){
        kg=x;
    }
    void print(){
        cout<<"Weight in kg"<<kg<<endl;
    }

    //preincrement operator overloading 

    void operator++ (){
        ++kg;
    }

    void operator++(int){
        kg++;
    }
   
    void operator--(){
        --kg;
    }
    void operator--(int){
        --kg;
    }

    
    

};
int main(){

   
    int weight;
    cout<<"Enter weight "<<endl;
    cin>>weight;
    Weight obj(weight);
    cout<<"Before any increment operator "<<endl;
    obj.print();
    ++obj;

    cout<<"After prefix increment overloading "<<endl;
    obj.print();
    obj++;
    cout<<"After postfix increment overloading "<<endl;
    obj.print();

    cout<<"After prefix decrement overloading "<<endl;
    --obj;
     obj.print();
    cout<<"After postfix decrement overloading "<<endl;
    obj--;
    obj.print();


}