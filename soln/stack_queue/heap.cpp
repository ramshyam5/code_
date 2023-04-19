#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int *arr;
    int size;//currently elements in min heap
    int capacity;//total number of elements min heap can store

    Heap(int cap);
    void insertion(int node);
    int delete_heap();
    void Minheapify(int i);
    void Display();

};
Heap::Heap(int cap){
    size=0;//initilally number of elements in heap =
    capacity=cap;
    arr=new int[capacity];

}

void Heap::insertion(int node){
    if(size==capacity){
        cout<<"Heap overflow"<<endl;
        return;
    }
    size++;
    int i=size-1;
    arr[i]=node;
    int parent=(i-1)/2;
    while(i!=0 && arr[parent]>arr[i]){
        swap(arr[parent],arr[i]);
        i=parent;
        parent=(i-1)/2;
    }
}
void Heap::Minheapify(int i){
    int smallest=i;
    int right_child=2*i+2;
    int left_child=2*i+1;
    if(i<size && arr[left_child]<arr[smallest] )smallest=left_child;
    if(i<size && arr[right_child]<arr[smallest])smallest=right_child;
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        Minheapify(smallest);
    }

}
int Heap::delete_heap(){
    if(size==0){
        cout<<"Heap underflow"<<endl;
        return INT_MIN;
    }
    if(size==1){
        size--;
        return arr[0];
    }

    int root=arr[0];
    arr[0]=arr[size-1];
    size--;
    Minheapify(0);
    return root;

}
void Heap::Display(){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){

    int n;
    cout<<"Enter size of heap"<<endl;
    cin>>n;
    Heap hp(n);
    int choice;
    while(1){
    cout<<"Enter choice"<<endl;
    cout<<"1.insert"<<endl<<"2.delete"<<endl<<"3.display"<<endl;
    cin>>choice;
    if(choice==1){
        int node;
        cout<<"Enter element to insert"<<endl;
        cin>>node;
        hp.insertion(node);
    }
    else if(choice==2){
        cout<<"Element delete:: "<<hp.delete_heap()<<endl;
    }
    else if(choice==3){
        hp.Display();
    }
    else exit(1);
    }

}