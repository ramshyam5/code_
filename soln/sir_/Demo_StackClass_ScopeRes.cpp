
// C++ manipulators
#include<iostream> 
#include<iomanip>
using namespace std; 


class stack
{
   //  member data
   private:
      int  *a,top,size;
   public:
      int  n;
   //  member methods
   private:
      int isempty(void);
      int isfull(void);
   public:
      stack(void);
      ~stack(void);
      int push(int x);
      int pop(void);
      void display(void);
      
};  // end of class stack

//  definition of the member methods
      int stack::isempty(void)
      {
         return(top==-1);
      }
      int stack::isfull(void)
      {
         return(top==(size-1));
      }

   stack::stack(void)
   {
      cout<<"Stack obj initialzation method"<<endl;
      size=10;  a=new int[size];
      top=-1; n=-1;  
   }
   stack::~stack(void)
   {
      cout<<"Stack obj destruction method"<<endl;
      delete [] a;
   }
   int stack::push(int x)
   {
      if(!isfull())
         {
            a[++top]=x;  n++;
            return(1);
         }
      else
         {  cout<<"Stack overflow"<<endl;
            return(-1);
         }
   }
   int stack::pop(void)
   {
      if(!isempty())
         {
            int x=a[top--]; n--;
            return(x);
         }
      else
         {  cout<<"Stack underflow"<<endl;
            return(-1);
         }
   }
   void stack::display(void)
   {  
      cout<<"Displaying Stack ::"<<endl;
      cout<<"     |    | "<<endl;
      for(int i=top;i>=0;i--)
         {
            cout<<"     | "<<a[i]<<" | "<<endl;
            cout<<"     |__"<<"__| "<<endl;  
         }
         cout<<"//////////////////"<<endl;
   }

int main(void) 
{ 
     stack s1;

     cout<<"size of an object instance"<<sizeof(s1)<<endl;

     //s1.initstk();
     /*s1.push(10);
     s1.push(20);
     s1.display();
     s1.push(30);
     cout<<s1.pop()<<" "<<s1.pop()<<endl;
     s1.pop();
     */
     //s1.clearstk();
} 