#include<bits/stdc++.h>

#include"bst.h"
using namespace std;
void bfs(bst& b){
    cout<<"Enter the number of elements you want to insert"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the data"<<endl;
    int data;
    for(int i=0; i<n; i++){
        cin>>data;
        b.insertion(data);
    }
    queue<TreeNode*> q;
    q.push(b.root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
        cout<<temp->data<<" ";
        q.pop();
    }
    cout<<endl;
}
void dfs(bst& b){
    stack<TreeNode*> s;
    s.push(b.root);
    while(!s.empty()){
        TreeNode* temp = s.top();
         s.pop();
        if(temp->left)s.push(temp->left);
        if(temp->right)s.push(temp->right);
        cout<<temp->data<<" ";
       
    }
}
int main(){
    bst b;
    bfs(b);
    dfs(b);
}