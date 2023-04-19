#include<iostream> 
#include<iomanip>
using namespace std;

class sal
{
    float gross,basic;

  public:
   const int &dummy;
   static float  da;
    const int bonus;

   sal(float);
   ~sal();
   float salCalc(void);
   static float daHike(float d);
   void display(void) const;
}; 

  sal::sal(float b=10000):bonus(2000), dummy(bonus)
   {
      cout<<"constr sal"<<endl;
      gross=basic=b;
   }
   sal::~sal()
   {
      cout<<"destr sal"<<endl;
   }
   float sal::salCalc(void)
   {
       gross += (bonus+(basic*da/100));
       return(gross);
   }
   float sal::daHike(float d)
   {
      da+=d;
   }
   void sal::display(void) const
   {
      cout<<"Salary details::::::::::::"<<endl;
      cout<<setw(20)<<setfill('.')<<"Basic"<<setw(12)<<basic<<endl;
      cout<<setw(20)<<setfill('.')<<"Bonus"<<setw(12)<<bonus<<endl;
      cout<<setw(20)<<setfill('.')<<"Da ("<<da<<")"<<setw(12)<<(basic*da/100)<<endl;
      cout<<setw(30)<<setfill('=')<<" "<<endl;
      cout<<setw(20)<<setfill(' ')<<"Gross "<<setw(12)<<gross<<endl;
   }

   float  sal::da=4;

   sal  ceo(100000);

  int main(void)
  {
      sal  s1Per;
      {
          sal  s2Per(50000);
          const sal  sTemp;
          s2Per.display();
          sTemp.display();

          sal::daHike(3);
          s2Per.display();
      }

      s1Per.display();
      ceo.display();
  }


