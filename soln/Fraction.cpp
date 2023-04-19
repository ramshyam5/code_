/*Implement a Fraction class which performs the following operations:
Add (+), Subtract (-), Multiply (*), Divide (/).*/

#include<bits/stdc++.h>
using namespace std;

class Fraction{

    public:
    double num,denom;
    Fraction(int n=0,int d=0):num(n),denom(d){}
    void display();

    Fraction operator+(Fraction f){
        Fraction ans;
        ans.num=num*f.denom+denom*f.num;
        ans.denom=denom*f.denom;
        return ans;
    }


};

void Fraction::display(){
    cout<<"Fraction is :: "<<num<<"/"<<denom<<endl;
}

int main(){
    double n,d;
    cout<<"Enter numerator and denominator"<<endl;
    cin>>n>>d;
    Fraction f1(n,d);
    f1.display();
    cout<<"Enter numerator and denominator"<<endl;
    cin>>n>>d;
    Fraction f2(n,d);
    f2.display();

    cout<<"Addition: "<<endl;
    Fraction f3;
    f3=f1+f2;
    f3.display();


}