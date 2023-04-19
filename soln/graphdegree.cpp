#include<iostream>
#include <list>
#include <queue>
#include <bits/stdc++.h>
    using namespace std;
class Graph
{
    int V;                               // number of vertices
    list<int> *adj;                      // pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]); // DFS utility function
public:
    Graph(int V);                  // constructor
    void addEdge(int v, int w);    // function to add an edge to the graph
    void BFS(int s);               // function for BFS traversal of the graph starting
    void DFS(int v); // function for DFS traversal of the graph starting
    
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list
}
void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    queue<int> queue;
    visited[s] = true;
    queue.push(s);
    list<int>::iterator i;
    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
}
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
}
void printDegrees()
{
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << " has degree " << adj[i].size() << endl;
    }
}
void computeDegreeDistribution()
{
    vector<int> degreeCount(V, 0);
    for (int i = 0; i < V; i++)
    {
        int degree = adj[i].size();
        degreeCount[degree]++;
    }
    cout << "Degree Distribution:\n";
    for (int i = 0; i < V; i++)
    {
        if (degreeCount[i] > 0)
        {
            cout << "Degree " << i << ": " << degreeCount[i] << "
                nodes\n ";
        }
    }
}
void countConnectedComponents()
{
    vector<bool> visited(V, false);
    vector<int> componentSizes;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            int componentSize = dfs(i, visited);
            componentSizes.push_back(componentSize);
        }
    }
    int numComponents = componentSizes.size();
    cout << "Number of connected components: " << numComponents
         << endl;
    cout << "Size distribution of connected components:\n";
    sort(componentSizes.begin(), componentSizes.end());
    for (int size : componentSizes)
    {
        cout << size << " ";
    }
    cout << endl;
}
int dfs(int v, vector<bool> &visited)
{
    visited[v] = true;
    int componentSize = 1;
    for (int neighbor : adj[v])
    {
        if (!visited[neighbor])
        {
            componentSize += dfs(neighbor, visited);
        }
    }
    return componentSize;
}
int main()
{
    Graph g;
    int option;
    int v, w;
    bool directed;
    do
    {
        cout << "Select an option:\n";
        cout << "1. Add edge\n";
        cout << "2. Remove edge\n";
        cout << "3. Depth First Search\n";
        cout << "4. Breadth First Search\n";
        cout << "5. Display node degree information\n";
        cout << "6. Display degree distribution\n";
        cout << "7. Display number of connected components\n";
        cout << "8. Display size distribution of connected components\n ";
            cout
             << "9. Exit\n";
        cout << "Option: ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1:
            cout << "Enter source vertex: ";
            cin >> v;
            cout << "Enter target vertex: ";
            cin >> w;
            cout << "Is the edge directed? (1 for yes, 0 for no): ";
            cin >> directed;
            g.addEdge(v, w, directed);
            break;
        case 2:
            cout << "Enter source vertex: ";
            cin >> v;
            cout << "Enter target vertex: ";
            cin >> w;
            g.removeEdge(v, w);
            break;
        case 3:
            cout << "Enter starting vertex: ";
            cin >> v;
            g.DFS(v);
            break;
        case 4:
            cout << "Enter starting vertex: ";
            cin >> v;
            g.BFS(v);
            break;
        case 5:
            g.displayNodeDegreeInfo();
            break;
        case 6:
            g.displayDegreeDistribution();
            break;
        case 7:
            cout << "Number of connected components: " << g.getNumConnectedComponents() << endl;
            break;
        case 8:
            g.displayConnectedComponentSizeDistribution();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
            break;
        }
        cout << endl;
    } while (option != 9);
    return 0;
}