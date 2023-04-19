// To Illustrate the overloading of <<  >>  = (deep copy) operators in complex class

#include<iostream>
using namespace std;

class complex
{
	float rl, img;
	float  *ptr;
	public:
		float arg, amp;

		complex(float f1=1.0,float f2=1.0)   //constructor with default arguments
		{
			//cout<<"constructing a complex obj"<<endl;
			rl=f1; img=f2;
			ptr= new float(rl+img);
		}
		
		~complex() // destructor
		{    //cout<<"destroying a complex object"<<endl;
		   delete  ptr;
		}

        // member functions
		void DispComplex(void) const;
		void operator=(const complex &c);
		
		friend ostream & operator<<(ostream &x, const complex &c);  // enables cascaded calls
		
};  // End of class definition

//.........................................................
//  Member function definitions
void complex::DispComplex(void) const
{
    cout<<rl;
    if(img>=0)
    {  cout<<" + "; cout<<img<<"i"<<endl; }
    else
    {  cout<<" - "; cout<<-img<<"i"<<endl;}
}


//  assignment = opeartor overloading using member function
//  to enable deep copying
void complex::operator=(const complex &c)
{   // deep copying
    rl=c.rl; img=c.img;
    delete ptr;
    ptr= new float(c.rl+c.img);
     
    return;
}


 //  friend function body operator<<
  
  ostream & operator<<(ostream &x, const complex &c)
  {
    x<<c.rl;
    if(c.img>=0)
    {  cout<<" + "; cout<<c.img<<"i"<<endl; }
    else
    {  cout<<" - "; cout<<-c.img<<"i"<<endl;}
    
    return x;
  }
//..........................................................
int main()
{
   complex a;
   
   {
       complex b(2.0,3.5);
       
       cout<<a;
       
       a=b;
       
       cout<<a<<b;
       
   }
   
   cout<<a;
   return 0;
}
