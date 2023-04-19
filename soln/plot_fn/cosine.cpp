#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter initial degree"<<endl;
    int a,b,step;
    cin>>a;
    cout<<"Enter final degree"<<endl;
    cin>>b;
    cout<<"Enter step"<<endl;
    cin>>step;
    char c;
    cout<<"enter char"<<endl;
    cin>>c;
    for(double i =0; i<110; i++){
        cout<<'=';
    }
    cout<<endl;
    for(double i =a; i<=b; i+=step){
        int x = floor(cos(i*(3.14/180))*50);
        if(x>0){
            cout<<setw(55)<<setfill(' ')<<"|"<<setw(x)<<setfill(c)<<'+'<<endl;
        }
        if(x<0){
            x = abs(x);
            cout<<setw(55-x)<<setfill(' ')<<"|"<<setw(x)<<setfill(c)<<'+'<<endl;
        }
    }
}