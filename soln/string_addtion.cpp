#include<bits/stdc++.h>
using namespace std;
//function for calculating addtion of large number 
void largeadd(string s1,string s2){
    if(s1.size()>s2.size()){
        swap(s1,s2);
    }
    int l1=s1.size();
    int l2=s2.size();
    int carry=0;
    string ans;
    int diff=(s2.size()-s1.size());
    for(int i=s1.size()-1;i>=0;i--){
        int a=(s1[i]-48)+(s2[i+diff]-48)+carry;
        ans+=to_string(a%10);
        carry=a/10;
    }

    for(int i=l2-l1-1;i>=0;i--){
       int sum=(s2[i]-48)+carry;
       ans+=to_string(sum%10);
       carry=sum/10;
    }

    if(carry>0)ans+=to_string(carry);
    reverse(ans.begin(),ans.end());
    cout<<"sum of "<<s1<<"  ans "<<s2<<" is "<<ans<<endl;
}
int main(){
    string s1,s2;
    cout<<"Enter first Number "<<endl;
    //Taking input from user
    cin>>s1;
    cout<<"Enter second Number "<<endl;
    cin>>s2;
    largeadd(s1,s2);
}