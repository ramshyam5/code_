// Illustration showing that static members can be inherited 
// and static methods can be  overridden as well

#include<iostream>


using namespace std;

class B   // Base class
{    public: 
     int  x; 
     static int s;
     
     static void  fstat(void) { cout<<"B::fstat :"<<s;}
};

int  B::s=10;
  
class D : public B // Derived class
{   
    // inhertits  B::x, B::s  B::fstst as public
    public: 
    	static void  fstat(void) { cout<<"D::fstat :"<<s;}
};

int main(void)
{
   B b;
   D d;
   
   b.x;
   B::s;   //  10
   B::fstat(); // B::fstat :10

   d.x;
   D::s;   // 10
   D::fstat(); // B::fstat :10

}