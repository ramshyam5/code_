//function for calculating addition of large number
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
//declaring function for calculating multiplication of large number
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

vector<int> largefac(int N){
    vector<int>temp;
    temp.push_back(1);
    for(int i=2;i<=N;i++){
         int carry=0;
         for(int j=0;j<temp.size();j++){
            int val=temp[j]*i+carry;
            temp[j]=val%10;
            carry=val/10;
         }
         while(carry!=0){
            temp.push_back(carry%10);
            carry/=10;
         }
    }
    reverse(temp.begin(),temp.end());
    return temp;
}