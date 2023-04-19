#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

int  g=0;  //global variable

void fn_val(int zz)
{
   zz++;
}

void fn_addr(int *zz)
{
   (*zz)++;
}

void fn_ref(int &zz)
{
   zz++;
}

int &fn_retRef(int zz)
{
    g=zz;   g+=2;
    cout<<"Within fu_retref g= "<<g<<endl; 
    return(g);
}

float sum(int x, int y)
{
	return(x+y);
}

float sub(int x, int y)
{
	return(x-y);
}

int fact(int x)
{
	long int res=1;
	for(int i=1;i<=x;i++)
		res*=i;
	return(res);
}
float execute(float (*fnp)(int,int))
{
	float  f=(*fnp)(2,3);
}


int  main(void)
{

	int x=5;
	int  &r1x=x;
	int  &r2x=r1x;
	int  &r3x=x;

	cout<<setw(6)<<x<<setw(6)<<r1x<<setw(6)<<r2x<<setw(6)<<r3x<<endl;
	r2x++;
	cout<<setw(6)<<x<<setw(6)<<r1x<<setw(6)<<r2x<<setw(6)<<r3x<<endl;
   
	int  a1[4]={2,4,6,8};

	int  &a3=a1[2];
	int  *p=a1;
	int *&q=p;
	cout<<setw(6)<<a1[2]<<setw(6)<<a3<<setw(6)<<p[2]<<endl;

	int  b1[2][3]={{1,2,3},{4,5,6}};
	int  &b2=b1[0][1];

    
    ///////////////////////////////////////////////////////////////////////////////
    // Different Parameter Passing
    //  Call by Value, Call by Address Call by Reference

	int  z=10;

    cout<<"Before aclling"<<z<<endl;
	fn_val(z);
	cout<<"After call by value"<<z<<endl;
	fn_addr(&z);
	cout<<"After call by address"<<z<<endl;
	fn_ref(z);
    cout<<"After call by reference"<<z<<endl;

    //int &h=12;

    ///////////////////////////////////////////////////////////////////////////////
    //  RETURNING REFERENCES
    fn_retRef(z)=5;
    cout<<"After calling fu_retref g= "<<g<<endl; 


    ///////////////////////////////////////////////////////////////////////////////
    // References & Constants
	int d=20;
    int  &dr=d;
    const int &cdr1=d;
    int const &cdr2=d;
    //int  & const drc=d;         //  error: ‘const’ qualifiers cannot be applied to ‘int&’
    //  const int & const cdrc=d;   // error: ‘const’ qualifiers cannot be applied to ‘const int&’

    cout<<setw(6)<<d<<setw(6)<<(++d)<<setw(6)<<(++dr)<<endl;  
    // cout<<setw(6)<<(++cdr1)<<setw(6)<<(++cdr2)<<endl;   //   error: increment of read-only reference ‘cdr2’

    const int e=30;
    // int  &er=e;     //  error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
    const int &cer1=e;
    int const &cer2=e;
    cout<<setw(6)<<e<<endl;
    // cout<<setw(6)<<(++e)<<setw(6)<<(++cer1)<<endl;  //  error: increment of read-only variable ‘e’

    //int &f=90;  // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    const int &f=90;
    cout<<f<<endl;

    ////////////////////////////////////////////////////////////////////////
   // Function pointers
    float (*fp[2])(int,int)={&sum, &sub};  // fp is a function ptr array of size which can point 
    //to any functions with prototype int (int,int)
    for(int u=0;u<2;u++)
    	cout<<execute(fp[u])<<endl;

    int  (*ff)(int)=&fact;

    cout<<(*ff)(5)<<endl;
   
    
}