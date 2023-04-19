#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cout<<"Enter the name"<<endl;
    cin>>str;
    int row=str.size();
    cout<<"------------"<<endl;
    for(int i=0;i<row;i++){
        for(int space=0;space<i;space++){
            cout<<" ";
        }
        for(int j=i;j<row;j++){
            cout<<str[j];
        }
        for(int j=row-2;j>=i;j--){
            cout<<str[j];
        }
        cout<<endl;
    }


}