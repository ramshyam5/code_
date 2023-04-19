#include<bits/stdc++.h>
using namespace std;
//function for calculating largemultiply
string largemultiply(string s1,string s2){
    int l1=s1.size();
    int l2=s2.size();
    if(l1==0||l2==0)return "0";
    int pow=0;
    int k=l1+l2-1;
    vector<int>temp(l1+l2,0);
    for(int i=l1-1;i>=0;i--){
        k=l1+l2-1-pow;
        int n1=(s1[i]-48);
        int carry=0;
        for(int j=l2-1;j>=0;j--){
            int n2=(s2[j]-48);
            int sum=n1*n2+temp[k]+carry;
            temp[k]=sum%10;
            carry=sum/10;
            k--;
        }
        if(carry>0){
            temp[k]=carry;
        }
        pow++;
    }
    int i=0;
    while(temp[i]==0)i++;
    string ans="";
    while(i<temp.size()){
        ans+=to_string(temp[i]);
        i++;
    }
    if(ans.size()==0)return "0";
    return ans;
}
int main(){
    string s1,s2;
    cout<<"Enter first number "<<endl;
    cin>>s1;
    cout<<"Enter second number "<<endl;
    cin>>s2;
    cout<<"Multiplication is "<<largemultiply(s1,s2)<<endl;

}