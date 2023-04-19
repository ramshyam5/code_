#include<bits/stdc++.h>
using namespace std;

class Counter{
    private: int count;
    public:
    Counter(){count =0;}
    Counter(int c){
        count = c;
    }
    int getCount(){
        return count;
    }
    //prefix;
    Counter operator++(){
        count++;
        return *this;
    }
    //postfix 
    Counter operator++(int i){
        Counter temp(count);
        count++;
        return temp;
    }
};
int main(){
    Counter c1,c2(5);
    Counter c3 = ++c2;
    ++c1;
    cout<<c3.getCount()<<endl;
    cout<<c1.getCount()<<endl;
    c3 = c2++;
    c2++;
    ++c1;
    cout<<c2.getCount()<<endl;
    cout<<c1.getCount()<<endl;
    cout<<c2.getCount()<<endl;
    cout<<c3.getCount()<<endl;
}