#include<iostream> 
#include<iomanip>
using namespace std; 



class demo
{
   //  member data
   public:
      int  x;

   //  member methods
      demo(int n);
      demo &f1(void);
      demo &f2(void);
      demo &f3(void);
      
};

      demo::demo(int n)
      {
         x=n;
      }
      demo &demo::f1(void)
      { x++; return *this;}
      demo &demo::f2(void)
      { x+=2; return *this;}
      demo &demo::f3(void)
      { x+=3; return *this;}
      
int main(void)
{
   demo  a(5);

   //a.f1(); 
   //a.f2();
   a.f3().f2().f1();
   
   cout<<a.x<<endl;

}