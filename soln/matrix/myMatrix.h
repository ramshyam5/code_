#include<bits/stdc++.h>
using namespace std;

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
