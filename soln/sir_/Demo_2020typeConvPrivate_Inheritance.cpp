// illustrating the issue of implicit non-conversion of 
// derived object reference to base reference  
// when private mode of Inheritance is used

#include<iostream>

using namespace std;

class teacher
{};
class teachAssistant : public teacher  // change the mode to private to observe the difference
{};


// global functions

void teach(const teacher &t)
{  
  cout<<"teach()"<<endl;  
}

void attendLecture(const teachAssistant &ta)
{  
  cout<<"attendLecture()"<<endl; 
}

int main()
{
   teacher x;

   teachAssistant y;

   teach(x);  // works trivially
   teach(y); // works when Inheritance mode is public; implicit type conversion from derived to base by the compiler

   // attendLecture(x);  // doesn't work at all; base type can never be converted to derived type no matter what the mode is
   attendLecture(y);  // works trivially
 
}
