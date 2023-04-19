#include <iostream>
 using namespace std;
class vehicle 
{
     public : 
     int wheels, speed;
    vehicle(int w = 4, int sp = 50) 
    {
         wheels = w;
         speed = sp;
        
    }
    void readval(void) 
    {
         cout << "Enter No. of wheels : ";
         cin >> wheels;
         cout << "Enter Speed (in Km/h): ";
         cin >> speed;
        
    }
    void show(void) 
    {
         cout << " Showing Vehicle class." << endl;
         cout << "No. of Wheels = " << wheels << endl;
         cout << "Speed = " << speed << " Km/h" << endl;
        
    }
    
};
class car : public vehicle 
{
     public :  
     int passengers;
    car(int p = 4) 
    {
         passengers = p;
    
    }
    void readval(void) 
    {
        vehicle::readval();
        cout << "Enter No. of Passengers : ";
        cin >> passengers;
        
    }
    void show(void) 
    {
        cout << "showing of car class" << endl;
         vehicle::show();
         cout << "No. of Passengers = " << passengers << endl;
    
    }
    
};
 class truck : public vehicle 
{
     public :  int loadlim;
    truck(int ll = 25) 
    {
         loadlim = ll;
        
    }
     void readval(void) 
    {
        vehicle::readval();
        cout << "Enter Load limit (in Tons) : ";
        cin >> loadlim;
        
    }
     void show(void) 
    {
          cout << "showing of truck class" << endl;
           vehicle::show();
          cout << "Max Load Limit = " << loadlim << endl;
    }
};
int main(void)
{
    cout << "Creating object 'vehcl' for Vehicle class" << endl;
    vehicle vehcl;
    vehcl.readval();
    vehcl.show();
    cout << "Creating object car for Car class " << endl;
    car car;
    car.readval();
    car.show();
    cout << "Creating object trck Vehicle Object" << endl;
    truck trck;
    trck.readval();
    trck.show();
    cout << "Compairing the speed:" << endl;
    if (car.speed > trck.speed)
    {
        cout << "Speed of car > Speed of truck" << endl;
    }
    else if (car.speed < trck.speed)
    {
        cout << "Speed of car < Speed of truck" << endl;
    }
    else
    {
        cout << "Speed of car = Speed of truck" << endl;
    }
}