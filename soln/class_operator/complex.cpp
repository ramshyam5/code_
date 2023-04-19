#include<bits/stdc++.h>
using namespace std;
class Complex{
    private:
    double real,img;
    public:
    friend ostream& operator <<(ostream& os, Complex& c);
    friend istream& operator >>(istream& is, Complex& c);

    bool operator == (Complex&c){
        if(real == c.real && img == c.img) return true;
        else return false;
    }
    bool operator !=(Complex&c){
        if(real == c.real && img == c.img) return false;
        else return true;
    }

    Complex operator +(Complex &c){
        Complex sum;
        sum.real = real+c.real;
        sum.img = img+c.img;
        return sum;
    }
    Complex operator -(Complex& c){
        Complex diff;
        diff.real = real-c.real;
        diff.img = img -c.img;
        return diff;

    }
    Complex operator *(Complex &c){
        Complex mul;
        mul.real = c.real*real - c.img*img;
        mul.img = c.real*img + c.img*real;
        return mul;
    }
    Complex operator /(Complex &c){
        Complex div;
        div.real = (c.real*real - c.img*img)/(c.real*c.real - c.img*c.img);
        div.img = (c.real*img + c.img*real)/(c.real*c.real - c.img*c.img);
        return div;
    }
    Complex operator !(){
        Complex conj;
        conj.real = real;
        conj.img = -img;
        return conj;
    }
    // void operator =(Complex& c){
    //     c.real = real;
    //     c.img = img;
    // }
    double operator [](int i){
        if(i==0){
            return real;
        }
        if(i==1){
            return img;
        }
        return 0.00;
    }
};
ostream& operator <<(ostream& os, Complex& c){
    os<<c.real<<'+'<<c.img<<"i"<<endl;
    return os;
}
istream& operator >>(istream& is, Complex& c){
    cout<<"enter real part"<<endl;
    is>>c.real;
    cout<<"entrer img part"<<endl;
    is>>c.img;
    return is;
}

int main(){
    Complex c1,c2,c3,c4,c5,c6,c7;
    cin>>c1;
    cin>>c2;
    cout<<c1<<endl;
    cout<<c2<<endl;
    c3 = (!c1);
    c4 = (c1+c2);
    c5 = (c1-c2);
    c6 = (c1*c2);
    c7 = (c1/c2);
    cout<<"conjugate of c1 "<<c3<<endl;
    cout<<"Sum"<<c4<<endl;
    cout<<"diff"<<c5<<endl;
    cout<<"mul"<<c6<<endl;
    cout<<"div"<<c7<<endl;
    cout<<"compairing"<<(c1==c2)<<" "<<(c1!=c2)<<endl;
    cout<<c1[0]<<" "<<c1[1]<<endl;
    
}
