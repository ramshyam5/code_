#include<bits/stdc++.h>
using namespace std;

string largeAdd(string& n1,string& n2){
    int carry=0;
    int s =0;
    string sum="";
    int  i = n1.size()-1,j=n2.size()-1;
    while(i>=0 && j>=0){
        int a = n1[i]-'0';
        int b = n2[j]-'0';
        s =a+b+carry;
        sum+=to_string(s%10);
        carry = s/10;
        i--;
        j--;
    }
    while(i>=0){
        s = n1[i]-'0'+carry;
        carry = s/10;
        s = s%10;
        sum+=to_string(s);
        i--;
    }
    while(j>=0){
        s = n2[j]-'0'+carry;
        carry = s/10;
        s = s%10;
        sum+=to_string(s);
        j--;
    }
    if(carry!=0)sum+=to_string(carry);
    reverse(sum.begin(),sum.end());
    return sum;
}

int main(){
    cout<<"Enter the two large Numbers"<<endl;
    string n1,n2;
    cin>>n1>>n2;
    cout<<"The sum of two numbers is: "<<largeAdd(n1,n2)<<endl;
}