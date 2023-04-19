// Illustrating the implementation of output streaming opeartor << during inheritance

#include<iostream>

using namespace std;

class B
{
    public: int b1;
    B(int a=10) {b1=a;}
    ~B(){}
    friend  ostream &operator<<(ostream &x, const B &y)
    {  x<<"B::operator<<:"<<y.b1<<endl;  
       return x;
    }
};
class D : public B
{  
	public: int  d1;
	D(int a,int b): B(a),d1(b) {}
	~D(){}
	// Didn't inherit friend  osteam &operator<<(ostream &x, const B &y)
	friend  ostream &operator<<(ostream &x, const D &y)
    {  x<<"D::operator<<:"<<y.b1<<"  "<<y.d1<<endl;  
       return x;
    }

	
};

int main()
{
   B b;
   D d(5,2);

   cout<<b;
   cout<<d;
   
}
