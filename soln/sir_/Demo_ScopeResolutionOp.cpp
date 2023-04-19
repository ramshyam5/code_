#include<iostream>
using namespace std;

int  x=10;  //global variable

int  main(void)
{
	cout<<x<<endl;
	int  x=20;
	cout<<"  "<<x<<"  "<<::x<<endl;
	{
		cout<<"  "<<x<<"  "<<::x<<endl;
		int  x=30;
		cout<<"  "<<x<<"  "<<::x<<endl;
		{
			cout<<"  "<<x<<"  "<<::x<<endl;
			{
				cout<<"  "<<x<<"  "<<::x<<endl;
			}
			cout<<"  "<<x<<"  "<<::x<<endl;
			int x=40;
		}
		cout<<"  "<<x<<"  "<<++(::x)<<endl;
	}
	cout<<"  "<<x<<"  "<<++(::x)<<endl;

}