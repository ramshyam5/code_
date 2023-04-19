/*Implement a Complex class which performs the following operations:
Add (+), Subtract (-), Multiply (*), Divide (/), Conjugate (!), Compare (==, !=),
Copy (=), Subscript ([ ]) – returns real for [0] and img for [1]; Input-Output (>>,<<)*/

#include<bits/stdc++.h>
using namespace std;

class Complex{
    double real,img;

    public:
    Complex(){}
    double operator[](int i);
    Complex operator!();
    friend istream& operator>>(istream &in,Complex &c); 
    friend ostream& operator<<(ostream &out,Complex &c); 
    Complex operator+(Complex &c);
    Complex operator-(Complex &c);
    Complex operator*(Complex &c);
    Complex operator/(Complex &c);
     bool operator==(Complex &c);
     bool operator!=(Complex &c);
   //  void operator=(Complex &c);

};

Complex Complex ::operator+(Complex &c){
    Complex ans;
    ans.real=real+c.real;
    ans.img=img+c.img;

    return ans;
}
Complex Complex::operator!(){
    Complex ans;
    ans.real=real;
    ans.img=-img;
    return ans;

}

Complex Complex::operator-(Complex &c){
    Complex diff;
    diff.real=real-c.real;
    diff.img=img-c.img;
    return diff;
}

Complex Complex::operator*(Complex&c){
     Complex mul;
     mul.real=real*c.real;
     mul.img=real*c.img;
     return mul;
}
Complex Complex ::operator/(Complex &cmp2){
        Complex c;
        c.real=(real*cmp2.real+img*cmp2.img)/(cmp2.real*cmp2.real+cmp2.img*cmp2.img);
        c.img=(img*cmp2.real-real*cmp2.img)/(cmp2.real*cmp2.real+cmp2.img*cmp2.img);
        return c;

}

bool Complex::operator==(Complex &c){
    if(real==c.real && img==c.img){
        return true;
    }
    return false;
}

bool Complex::operator!=(Complex &c){
    if(c.real!=real || c.img!=img){
        return true;
    }
    else return false;
}

// void Complex::operator=(Complex &c){
//     real=c.real;
//     img=c.img;
// }

istream& operator>>(istream &in,Complex &c){
    cout<<"Enter real part "<<endl;
    in>>c.real;
    cout<<"Enter imaginary part "<<endl;
    in>>c.img;

    return in;

}

ostream& operator<<(ostream &out,Complex &c){
    out<<c.real<<"+"<<c.img<<"i"<<endl;

    return out;
}

double Complex::operator[](int i){
     if(i==0)return real;
     else return img;

}

int main(){
    Complex c1,c2,c3,c4,c5,c6,c7;
    cin>>c1;
    cin>>c2;
    cout<<c1<<endl;
    cout<<c2<<endl;
    c3=c1+c2;
    cout<<c3<<endl;
    c4=c1-c2;
    c5=c1*c2;
    c6=(!c1);
    c7=c1/c2;
    cout<<c3<<endl<<c4<<endl<<c5<<endl<<c6<<endl<<c7<<endl;
    

}