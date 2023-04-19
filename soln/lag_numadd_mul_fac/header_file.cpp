#include<bits/stdc++.h>
using namespace std;
#include"header.h"
//user defined header file which contains largeAdd(),largeMultiply(),and largefun()function

int main(){
    int n;
    cout<<"Enter the operation you want to perform :"<<endl<<"Enter 1 for addition "<<endl<<"Enter 2 for multiplication"<<endl<<"Enter 3 for factorial"<<endl;
    cin>>n;
    string s1,s2;
    int N;
    vector<int>ans;
    switch (n)
    {
    case  1:cout<<"Enter first Number for addtion ";
            cin>>s1;
            cout<<"Enter second number for addition";
            cin>>s2;
            largeadd(s1,s2);
        break;


    case 2: cout<<"Enter first number  "<<endl;
            cin>>s1;
            cout<<"Enter second number " <<endl;
            cin>>s2;
            cout<<"Multilication is "<<largemultiply(s1,s2)<<endl;
            break;
    case 3:cout<<"Enter number to find factorial "<<endl;
           cin>>N;
          ans= largefac(N);
          cout<<"factorial is "<<endl;
          for(int i=0;i<ans.size();i++){
           cout<<ans[i];
         }
           break;             
    default:
        break;
    }
    
    
}