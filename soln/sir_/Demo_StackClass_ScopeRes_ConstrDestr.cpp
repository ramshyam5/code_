
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

   public:  // public interface
      stack(void);  // constrctor 0
      stack(int x);  // constrctor 1
      stack(int x, int v);  // constrctor 2
      ~stack();  // ****  SINGLE destructor method
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

   stack::stack(void)  // contructor method 0
   {
      int x=10; // set a default size value
      cout<<"Constrctor 0 Stack object "<<x<<endl;
      size=x;  a=new int[size];  // dynamic alloc
      top=-1; n=-1;  
   }
   
   stack::stack(int x)  // contructor method 1
   {
      cout<<"Constrctor 1 Stack object "<<x<<endl;
      size=x;  a=new int[size];  // dynamic alloc
      top=-1; n=-1;  
   }
   stack::stack(int x, int v)  // constrctor method 2
   {
      cout<<"Constrctor 2 Stack object "<<x<<endl;
      size=x;  a=new int[size];  // dynamic alloc
      top=-1; n=-1;  
      a[++top]=v; n++;
   }
   
   stack::~stack(void)  // destructor method
   {
      cout<<"Dectruction of Stack object "<<size<<endl;
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
     stack  s1;
   /*  stack ss(2);  // static allocation of a single stack object
     stack sss=2;
     stack s2[2]={4,7};  // static allocation of an array of 2 stack objects 
     stack s3[3]={{2,20},{5}}; // static allocation of an array of 3 stack objects with 1st ele given

     s3[1].display();

      //s1.initstk(2);
     s1.push(10);
     s1.push(20);
   */
     s1.display();
     {
        // nested scope
        stack *p=new stack(3,7); // dynamic allocation 
        //stack *q=new stack[4];   // dynamic allocation of an array of objects


        (*p).push(10);
        //p->display();

        //delete p;  
        //p->~stack();
        //delete [] q;  

     }

     s1.push(30);
     cout<<s1.pop()<<" "<<s1.pop()<<endl;
     s1.pop();
     //s1.clearstk();
   
} 