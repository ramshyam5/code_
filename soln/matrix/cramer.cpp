#include<bits/stdc++.h>
using namespace std;
#include"myMatrix.h"


int main(){
    int n;
    float div;
    cout<<"Enter number of equation "<<endl;
    cin>>n;
  //allocating space for equation matrix
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    cout<<endl;
    //filling matrix with coeffiecient
    cout<<"Enter coffiecient of varibles "<<endl;
    for(int i=0;i<n;i++){
        cout<<"coeficient of eq: "<<i+1<<endl;
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
   int *c=new int[n];
   cout<<endl;
   cout<<"Enter constant term "<<endl;
   for(int i=0;i<n;i++){
    cin>>c[i];
   }

   int deter_par=determinant(arr,n);

   int d[n];
   int count=0;
   for(int i=0;i<n;i++){
     int **help=new int*[n];
     for(int i=0;i<n;i++){
        help[i]=new int[n];
     }

     for(int j=0;j<n;j++){
         help[j][i]=c[j];

        for(int k=0;k<n;k++){
            if(k!=i){
                help[j][k]=arr[j][k];
            }
        }
     }
     d[i]=determinant(help,n);
     if(d[i]==0)count++;
     for(int i=0;i<n;i++){
        delete []help[i];
       
     }
      delete []help;
   }


   cout<<"Determinant of matrix "<<endl;
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
   }

   cout<<"D: "<<deter_par<<endl;

   for(int i=0;i<n;i++){
    cout<<"D: "<<i+1<<" "<<d[i]<<endl;
   }

   if(deter_par==0 && count==0)cout<<"No solution exit"<<endl;
   if(deter_par==0 && count!=0)cout<<"Infinite solution exist"<<endl;
   cout<<"Values of unknown variable arre "<<endl;
   for(int i=0;i<n;i++){
    float div=float(d[i])/float(deter_par); 
       cout << d[i] << "/" <<deter_par << " = " << div << endl;
    }

}