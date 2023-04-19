#include<bits/stdc++.h>
using namespace std;

int main(){
    int*** arr;
    arr = new int**[3];
    for(int i=0; i<3; i++){
        arr[i] = new int*[5];
    }
    int n1,n2,n3;
    cout<<"Enter the number of students in 2nd 3rd and 4th yr resp "<<endl;
    cin>>n1>>n2>>n3;
    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++){
           if(i==0){
             arr[i][j] = new int[n1];
           }
           if(i==1){
             arr[i][j] = new int[n2];
           }
           if(i==2){
             arr[i][j] = new int[n3];
           }
        }
    }
    srand(time(0));
    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++){
            if(i==0){
                for(int k=0; k<n1; k++){
                    arr[i][j][k] = rand()%100;
                }
            }
            if(i==1){
                for(int k=0; k<n2; k++){
                    arr[i][j][k] = rand()%100;
                }
            }
            if(i==2){
                for(int k=0; k<n3; k++){
                    arr[i][j][k] = rand()%100;
                }
            }
        }
    }
    for(int i=0; i<3; i++){
        if(i==0){
            cout<<"2nd year"<<endl;
        }
        if(i==2){
            cout<<"4th year"<<endl;
        }
        if(i==1){
            cout<<"3rd year"<<endl;
        }
        for(int j=0; j<5; j++){
            cout<<j+1<<"th subject"<<endl;
            if(i==0){
                for(int k=0; k<n1; k++){
                  cout<<"marks of "<<k+1<<"th student "<<arr[i][j][k]<<endl;
                }
            }
            if(i==1){
                for(int k=0; k<n2; k++){
                    cout<<"marks of "<<k+1<<"th student "<<arr[i][j][k]<<endl;
                }
            }
            if(i==2){
                for(int k=0; k<n3; k++){
                     cout<<"marks of "<<k+1<<"th student "<<arr[i][j][k]<<endl;
                }
            }
        }
    }
    //deallocation
    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++){
            delete [] arr[i][j];
        }
        delete [] arr[i];
    }
    delete [] arr;
}