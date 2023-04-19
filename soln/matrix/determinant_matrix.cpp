/*Write a program to dynamically allocate a 2-D array of size n x n and
perform. Create functions for allocating space, reading, displaying,
processing matrices and pass suitable parameters in the protype
- Matrix multiplication
- Determinant of the matrix*/

#include<bits/stdc++.h>
using namespace std;

class matrix{
     public:
     int row,col;
     matrix();
     int ** Allocatespace(int r,int c);
     void readmatrix(int **m);
     void displaymatrix(int **m);
     void matrixmultiply();
     void helper_matrix();
};

matrix::matrix(){
    row=0;
    col=0;
}

int ** matrix::Allocatespace(int r, int c){
   if(row==0 &&col==0){
       col=c;
       row=r;
   }
   int **m=new int*[row];
   for(int i=0;i<row;i++){
     m[i]=new int[col];
   }
   return m;

}

void matrix::readmatrix(int **m){
    cout<<"Reading matrix "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>m[i][j];
        }
    }
}

void matrix::displaymatrix(int **m){
    cout<<"Displaying matrix"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

void matrix::matrixmultiply(){
    matrix obj;
    int r1,c1,r2,c2;
    int **m1,**m2;
    cout<<"enter dimension for first matrix"<<endl;
    cin>>r1>>c1;
     m1=obj.Allocatespace(r1,c1); 
     obj.readmatrix(m1);
     obj.displaymatrix(m1);
     row=0,col=0;
     cout<<"Enter dimension of second matrix"<<endl;
     cin>>r2>>c2;
     m2=obj.Allocatespace(r2,c2);
     obj.readmatrix(m2);
     obj.displaymatrix(m2);

     cout<<"Multiplying two matrix "<<endl;

     if(c1!=r2){
        cout<<"Matrix multiplication not possible "<<endl;
        exit(1);
     }

     int **m3;
     m3=obj.Allocatespace(r1,c2);
     for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<r2;k++){
                m3[i][j]+=m1[i][k]*m2[k][j];
            }
        }
     }

     obj.displaymatrix(m3);

}
int determinant( int **matrix, int n) 
{  //matrix obj;
   int det = 0;
     int **submatrix=new int*[n];
   for(int i=0;i<n;i++){
     submatrix[i]=new int[n];
   }
   
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   return det;
}

void matrix:: helper_matrix(){
    matrix obj;
    int r,c;
    int **mar;
    cout<<"Enter dimension "<<endl;
    cin>>r>>c;
   mar= obj.Allocatespace(r,c);
   obj.readmatrix(mar);
   obj.displaymatrix(mar);
     
    int ans=determinant(mar,r);
    cout<<ans;

}

int main(){
    matrix m;
    // int row,col;
    // int **arr;
    // cout<<"Enter dimension of matrix "<<endl;
    // cin>>row>>col;
    // arr=m.Allocatespace(row,col);
    // m.readmatrix(arr);
    // m.displaymatrix(arr);
    //m.matrixmultiply();
    m.helper_matrix();

}


