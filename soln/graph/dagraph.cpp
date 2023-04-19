#include<bits/stdc++.h>
using namespace std;

class dag{
    private:
    int V;
    vector<vector<int>> adj;
    public:

    dag(){
        
    }
    dag(int V){
        this->V = V;
        vector<vector<int>> list(V);
        this->adj = list;
    }
    void addedge(int u, int v){
        adj[u].push_back(v);
    }
    void createEdge(){
        cout<<"Enter the number of edges"<<endl;
        int n; 
        cin>>n;
        cout<<"Enter the edges"<<endl;
        for(int i=0;i<n; i++){
            int u,v;
            cin>>u>>v;
            addedge(u,v);
        }
    }
    void dfs(vector<bool>& visited, vector<vector<int>>& paths, vector<int>& path, int node){
        visited[node] = true;
        path.push_back(node);
        if(node == V-1){
            paths.push_back(path);
        }
        else{
            for(int i =0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                    dfs(visited,paths,path,adj[node][i]);
                }
            }
        }
        visited[node]= false;
        path.pop_back();
    }
    vector<vector<int>> findallpaths(){
        vector<vector<int>> paths;
        vector<int> path;
        vector<bool> visited(V,false);
        dfs(visited,paths,path,0);
        return paths;
    }
    void bfs(vector<bool>& visited, vector<int>& component, int node){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int k = q.front();
            q.pop();
            component.push_back(k);
                for(int i =0; i<adj[k].size(); i++){
                    if(!visited[adj[k][i]]){
                        q.push(adj[k][i]);
                        visited[adj[k][i]] = true;
                    }
                }
            }
        }
    
    vector<vector<int>> findcomponenet(){
        vector<bool> visited(V,false);
        vector<vector<int>> comp;
        for(int i=0; i<V; i++){
           if(!visited[i]){ vector<int> component;
            bfs(visited,component,i);
            comp.push_back(component);}
        }
        return comp;
    }
    void display(void(*traversal)(int)){
        for(int i=0; i<V;i++){
            cout<<i<<" ,";
            for(auto j: adj[i]){
                traversal(j);
            }
            cout<<endl;
        }
    }
};
void printlist(int u){
    cout<<u<<" ";
}
int main(){
    dag graph(6);
    graph.createEdge();
    vector<vector<int>> paths;
    paths = graph.findallpaths();
    graph.display(printlist);
    vector<vector<int>> comp;
    comp = graph.findcomponenet();
    cout<<"path of graphs"<<endl;
    for(auto i: paths){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"Components of the graph"<<endl;
     for(auto i: comp){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}