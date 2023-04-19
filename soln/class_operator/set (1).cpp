#include<bits/stdc++.h>
using namespace std;

class Set{
    private:
    int* ptr;
    int size;
    public:
    Set(){

    }
    //copy constructor
    Set(Set& obj){
        size = obj.size;
        ptr = obj.ptr;
    }
    bool present(int a){
        for(int i=0; i<size; i++){
            if(ptr[i]==a) return true;
        }
        return false;
    }
    friend ostream& operator<<(ostream& os, Set& s);
    friend istream& operator>>(istream& os, Set& s);
    Set operator+(Set& s){
        Set ans;
        ans.size = size+s.size;
        int j=0;
        ans.ptr = new int[ans.size];
        for(int i=0; i<size; i++){
            if(!ans.present(ptr[i])){
                ans.ptr[j] = ptr[i];
                j++;
            }
        }
        for(int i=0; i<s.size; i++){
            if(!ans.present(s.ptr[i])){
                ans.ptr[j] = s.ptr[i];
                j++;
            }
        }
        ans.size = j;
        return ans;
    }
    Set operator -(Set& s){
        Set ans;
        ans.ptr = new int[size];
        int j=0;
        for(int i=0; i<size; i++){
            if(!s.present(ptr[i])){
                ans.ptr[j] = ptr[i];
                j++;
            }
        }
        ans.size = j;
        return ans;
    }
    Set operator *(Set& s){
        Set ans;
        ans.ptr = new int[size];
        int j =0; 
        for(int i=0; i<size; i++){
            if(s.present(ptr[i])){
                ans.ptr[j] = ptr[i];
                j++;
            }
        }
        ans.size = j;
        return ans;
    }
    bool operator <(Set& s){
        if(s.size>size) return false;
        int j=0;
        for(int i=0; i<s.size; i++){
            if(present(s.ptr[i])){
                j++;
            }
        }
        if(j==s.size) return true;
        else return false;
    }
    bool operator<=(Set& s){
        if(this->size == s.size && s<*this) return true;
        else return false; 
    }
    
};
ostream& operator<<(ostream& os, Set& s){
    os<<"{";
    for(int i=0; i<s.size; i++){
        os<<s.ptr[i]<<" ,";
    }
    os<<" }";
    return os;
}
istream& operator >>(istream& in, Set& s){
    cout<<"Enter the number of elements"<<endl;
    in>>s.size;
    cout<<"Enter the elements"<<endl;
    s.ptr = new int[s.size];
    int j=0;
    int p;
    for(int i=0; i<s.size; i++){
        in>>p;
        if(!s.present(p)){
            s.ptr[j] = p;
            j++;
        }
    }
    s.size = j;
    return in;
}

int main(){
    Set s1,s2,s3,s4,s5;
    cin>>s1;
    cin>>s2;
    s3 = (s1+s2);
    s4 = (s1-s2);
    s5 = (s1*s2);
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;
    cout<<(s1<s2)<<(s1<=s2)<<endl;
}