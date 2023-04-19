// illustrating the sequence of constr/destr call during inheritance

#include<iostream>

using namespace std;

class B
{
    public: int b1;
    B(int a=10) 
    {
       b1=a;
       cout<<"B(int) :"<<b1<<endl;
     }
    ~B(){cout<<"~B:"<<b1<<endl;}
    
};
class D : public B
{  
	public: int  d1;
	D(int a,int b): B(a),d1(b) 
   { cout<<"D(int,int):"<<b1<<"  "<<d1<<endl;}
  D(int b): d1(b) 
  { cout<<"D(int):"<<b1<<"  "<<d1<<endl;}
	~D()
   { cout<<"~D:"<<b1<<"  "<<d1<<endl; }
	
};

int main()
{
   B b;
   D d(5,2);
   D a(4);
}
