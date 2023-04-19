// Function Pointers Dynamic Binding in C++ Demo
#include<iostream>

using namespace std; 

int g=0; //global variable

float sum(int x,int y)  
{ return(x+y); }

float sub(int x,int y)  
{ return(x-y); }

long int fact(int x)  
{   long int res=1; for(int i=1;i<=x;i++)  res*=i;
    return(res);
}


int main(void)
{
	cout<<sum(2,3)<<endl;   
	cout<<sub(10,2)<<endl;
	
	float (*fp[2])(int,int)={&sum,&sub};

	cout<<(*fp[0])(2,3)<<endl;
	cout<<(*fp[1])(2,3)<<endl;
    
    int ch; cout<<"Enter your choice 1(sum) or 2(sub) :"; 
    cin>>ch;
    int a,b;  cout<<"enter 2 int values :"; cin>>a>>b;

	cout<<(*fp[ch])(2,3)<<endl;

}