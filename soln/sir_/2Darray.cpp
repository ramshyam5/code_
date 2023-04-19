#include<iostream>
#include<iomanip>

using namespace std; 


int **alloc2Darr(int r,int c)
{   
	int **arucu=new int*[r];
	for(int i=0;i<r;i++)
		arucu[i]=new int[c];
	return arucu;
}

void  read2Darr(int **a, int r, int c)
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			{
				cout<<"Enter "<<i<<j<<" th element value :"; cin>>(a[i][j]);
			}
}

void  disp2Darr(const int **a, int r, int c)
{
	for(int i=0;i<r;i++)
		{ for(int j=0;j<c;j++)
			cout<<setw(6)<<(a[i][j]);
		  cout<<endl;
		}
		
}


int main(void)
{
	int r,c;   
	cout<<"Enter rows & cols :"; cin>>r>>c;
    int  **p=alloc2Darr(r,c);

    read2Darr(p,r,c);
    disp2Darr((const int **)p,r,c);

}