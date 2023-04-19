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

string largeMult(string& n1, string& n2){
    int j = n2.size()-1;
    int stage =0;
    string sm ="";
    while(j>=0){
        int c=0;
        int m;
        string mult="";
        int i = n1.size()-1;
        while(i>=0){
            int mul = (n1[i]-'0')*(n2[j]-'0')+c;
            c = mul/10;
            m = mul%10;
            mult = mult+to_string(m);
            i--;
        }
        if(c!=0) mult+=to_string(c);
        reverse(mult.begin(),mult.end());
        int k = stage;
        string addend="";
        int p = sm.size()-1;
        while(k--){
            addend += sm[p];
            p--;
            sm.pop_back();
        }
        //cout<<mult<<" "<<sm<<endl;
        reverse(addend.begin(),addend.end());
        string prevsum = largeAdd(mult,sm);
        sm = prevsum+addend;
        stage++;
        j--;
    }
    return sm;
}
int main(){
    string n1,n2;
    cout<<"Enter the two numbers: "<<endl;
    cin>>n1>>n2;
    cout<<"The multiplication is: "<<largeMult(n1,n2)<<endl;
}