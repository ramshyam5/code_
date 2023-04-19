#include<iostream> 
#include<iomanip>
using namespace std;

class XYZ
{
    public:   int a;

    XYZ(int);  
    ~XYZ(); 
    //void fn(XYZ x);
    //XYZ  fn(XYZ x);
    XYZ &fn(XYZ &);
    void display(void);
}; 

    XYZ::XYZ(int s=5)
    {  a=s;  cout<<"Constr"<<endl; }
    XYZ::~XYZ(void)
    {  cout<<"Destructor"<<endl;}
    /*void XYZ::fn(XYZ x)
    { a=++(x.a); }
    
    XYZ XYZ::fn(XYZ x)
    { a=++(x.a); return x;}
    */
    XYZ &XYZ::fn(XYZ &x)
    { a=++(x.a); return x; }
    
    
    void XYZ::display(void)
    { cout<<"Value "<<a<<endl; }

  int main(void)
  {
      XYZ m(10),n; //  constructor got invoked
      m.display();
      n.display();
       
      XYZ z=m.fn(n);   // dectructor prompt twice
      m.display();
      n.display();  
  }


