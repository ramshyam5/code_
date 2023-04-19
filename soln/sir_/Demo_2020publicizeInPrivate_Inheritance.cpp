// illustrating publicizing privately inherited members in derived class

#include<iostream>

using namespace std;

class B
{
    int  b;	
	public:  int b1,b2;
	B(int x=1, int y=2): b(x), b1(x), b2(y){}
	~B(){}

};

class D: private B
{
	// inherited B::b but inaccessible from D
	// inherited B::b1 is accessed as private in D

   public:
    using B::b2;  // publicizing the privately inherited member
   	void fn(void)
   	{
   		// cout<<b<<endl; // can't access base's private members
   		cout<<b1<<b2<<endl; 
   	}

};


int main()
{
  D d;
  d.fn();
 //  cout<<d.b1;  // error!!! b1 is private in derived class D  
  cout<<d.b2;  // works; b2 has been explicitly publicized by D
 
}
