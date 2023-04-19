#include<bits/stdc++.h>
using namespace std;
int main(){
  double start ,end,length;
  char fillcharacter;
 cout<<"Enter the starting angle in radinas "<<endl;
 cin>>start;
 cout<<"Enter the ending andle in radina "<<endl;
 cin>>end;
 cout<<"Enter the step length "<<endl;
 cin>>length;
 cout<<"Enter the fillcharacter"<<endl;
 cin>>fillcharacter;
 for(int j=0;j<=110;j++)
 cout<<"=";
 cout<<endl;
 for(double i=start;i<=end;i+=length){
    double k=(i*3.14)/180.0;
    double t1=sin(3.14*k)*55;
    t1=t1/(3.14*k);
    int p=t1;
    // int p=floor(sin(i*3.14/180)*50);
    if(p>=0){
        cout<<setw(55)<<setfill(' ')<< "|"<<setw(p)<<setfill(fillcharacter)<<'+'<<endl;
    }
    else {
        p=abs(p);
        cout<<setw(55-p)<<setfill(' ')<<'+'<<setw(p)<<setfill(fillcharacter)<<"|"<<endl;
    }
 }  

}