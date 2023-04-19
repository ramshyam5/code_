#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
 cout<<"Enter number of lines"<<endl;
  cin>>n;
    vector<string>temp;
    int space=0;
    for(int i=0;i<=n;i++){
        string st;
        getline(cin,st);
        if(st.back()=='}') space--; 
        string tp="";
        for(int j=0;j<space;j++){
            tp+="  ";
        }
        tp+=st;
        temp.push_back(tp);
        if(st.back()=='{') space++;

    }
    for(auto str:temp){
        cout<<str<<endl;
    }
    return 0;
}