
// C++ manipulators
#include<iostream> 
#include<iomanip>
using namespace std; 

//  function prototypes
      int isempty(void);
      int isfull(void);
      void initstk(int x);
      void clearstk(void);
      int push(int x);
      int pop(void);
      void display(void);

// definition of the stack structure
struct stack
{
      int  *a,top,size;
      int  n; 
      
};  // end of struct stack

//  definition of the functions
      int isempty(stack s)
      {
         return(s.top==-1);
      }
      int isfull(stack s)
      {
         return(s.top==(s.size-1));
      }

   void initstk(stack s,int x)
   {
      s.size=x;  s.a=new int[s.size];
      s.top=-1; s.n=0;  
   }
   void clearstk(stack s)
   {
      delete [] s.a;
   }
   int push(stack s, int x)
   {
      if(!isfull(s))
         {
            s.a[++(s.top)]=x;  (s.n)++;
            return(1);
         }
      else
         {  cout<<"Stack overflow"<<endl;
            return(-1);
         }
   }
   int pop(stack s)
   {
      if(!isempty(s))
         {
            int x=s.a[s.top--]; s.n--;
            return(x);
         }
      else
         {  cout<<"Stack underflow"<<endl;
            return(-1);
         }
   }
   void display(stack s)
   {  
      cout<<"Displaying Stack ::"<<endl;
      cout<<"     |    | "<<endl;
      for(int i=s.top;i>=0;i--)
         {
            cout<<"     | "<<s.a[i]<<" | "<<endl;
            cout<<"     |__"<<"__| "<<endl;  
         }
         cout<<i;
         cout<<"//////////////////"<<endl;
   }


int main(void) 
{ 
     stack s1,s2; // instance of stack object

     cout<<"size of an object instance"<<sizeof(s1)<<endl;

     initstk(s1,2);
     //push(s1,10);
     //push(s1,20);
     display(s1);
    /* push(s1,30);
     cout<<pop(s1)<<" "<<pop(s1)<<endl;
     pop(s1);
     */

} 