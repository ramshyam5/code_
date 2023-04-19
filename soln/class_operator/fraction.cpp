#include<bits/stdc++.h>
using namespace std;
class fraction{
    private:
    int num,denom;
    public:
    friend ostream& operator<<(ostream& os, fraction& f);
    friend istream& operator>>(istream& os, fraction& f);
    bool operator <(fraction& f){
        if((num/denom)>((f.num)/f.denom)) return true;
        else return false;
    }
    bool operator >(fraction& f){
        if((num/denom)<((f.num)/f.denom)) return true;
        else return false;
    }
    bool operator == (fraction& f){
        if((num/denom)==((f.num)/f.denom)) return true;
        else return false;
    }
    bool operator !=(fraction&f){
        if((num/denom)!=((f.num)/f.denom)) return true;
        else return false;
    }
    int operator [](int i){
        if(i==0){
            return num;
        }
        return denom;
    }
    fraction operator +(fraction&f){
       fraction c;
        c.num = (num*f.denom + denom*f.num);
        c.denom = (f.denom*denom);
        c = *c;
        return c;
    }
    fraction operator -(fraction&f){
        fraction c;
        c.num = (num*f.denom - denom*f.num);
        c.denom = (f.denom*denom);
        c = *c;
        return c;
    }
    fraction operator *(fraction&f){
        fraction c;
        c.num = (num*f.num);
        c.denom = (f.denom*denom);
        c = *c;
        return c;
    }
    fraction operator /(fraction&f){
        fraction c;
        c.num = (num*f.denom);
        c.denom = (f.num*denom);
        c = *c;
        return c;
    }
    int gcd(int x, int y){
        int res = min(x,y);
        while(res>0){
            if(x%res == 0 && y%res ==0) break;
            res--;
        }
        return res;
    }
    // void operator =(fraction&f){
    //     num = f.num;
    //     denom = f.denom;
    // }
    fraction operator *(){
        fraction f;
        int k =gcd(num,denom);
        num/=k;
        denom/=k;
        f.num = num;
        f.denom = denom;
        return f;
    }
};
ostream& operator<<(ostream& os, fraction& f){
    os<<'('<<f.num<<')'<<'/'<<'('<<f.denom<<')'<<endl;
    return os;
}
istream& operator>>(istream& os, fraction& f){
    cout<<"Enter the num"<<endl;
    os>>f.num;
    cout<<"Enter the denom"<<endl;
    os>>f.denom;
    return os;
}
int main(){
    fraction f1,f2,f4,f5,f6;
    cin>>f1>>f2;
    fraction f3;
    f3 = f1+f2;
    f4 =f1-f2;
    f5 = f1*f2;
    f6 = f1/f2;
    cout<<" sum "<<f3<<" diff "<<f4<<" mul "<<f5<<" div "<<f6<<endl;
    cout<<(f1>f2)<<" "<<(f1==f2)<<" "<<(f1<f2)<<" "<<(f1!=f2)<<endl;
}