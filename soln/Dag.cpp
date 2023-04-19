#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class DAG {
private:
    int V; // number of vertices
    vector<int> *adj; // adjacency list

public:
    DAG(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    ~DAG() {
        delete[] adj;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void createGraph() {
        int u, v, n;
        cout << "Enter the number of edges: ";
        cin >> n;
        cout << "Enter the edges: \n";
        for (int i = 0; i < n; i++) {
            cin >> u >> v;
            addEdge(u, v);
        }
    }

    void displayGraph(void (*traversal)(int)) {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (auto j : adj[i]) {
                traversal(j);
            }
            cout << endl;
        }
    }

    void dfs(int u, vector<bool> &visited, vector<int> &path, vector<vector<int>> &paths) {
        visited[u] = true;
        path.push_back(u);
        if (u == V-1) {
            paths.push_back(path);
        }
        else {
            for (auto v : adj[u]) {
                if (!visited[v]) {
                    dfs(v, visited, path, paths);
                }
            }
        }
        visited[u] = false;
        path.pop_back();
    }

    vector<vector<int>> findAllPaths() {
        vector<bool> visited(V, false);
        vector<int> path;
        vector<vector<int>> paths;
        dfs(0, visited, path, paths);
        return paths;
    }

    void bfs(int u, vector<bool> &visited, vector<int> &component) {
        queue<int> q;
        visited[u] = true;
        q.push(u);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            component.push_back(v);
            for (auto w : adj[v]) {
                if (!visited[w]) {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
    }

    vector<vector<int>> findComponents() {
        vector<bool> visited(V, false);
        vector<vector<int>> components;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component;
                bfs(i, visited, component);
                components.push_back(component);
            }
        }
        return components;
    }
};
void printVertex(int v) {
    cout << v << " ";
}
int main() {
    // create the DAG graph
    DAG graph(6);

    // add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    // display the adjacency list of the graph using DFS traversal:-
    cout << "The adjacency list of the graph using DFS traversal: " << endl;
    graph.displayGraph(printVertex);

    // find all paths from vertex 0 to vertex 5
    cout << "All paths from vertex 0 to vertex 5: " << endl;
    vector<vector<int>> paths = graph.findAllPaths();
    for (auto path : paths) {
        for (auto v : path) {
            cout << v << " ->";
        }
        cout << endl;
    }

    // find the connected components of the graph using BFS traversal
    cout << "Connected components of the graph using BFS traversal: " << endl;
    vector<vector<int>> components = graph.findComponents();
    for (auto component : components) {
        for (auto v : component) {
            cout << v << "-> ";
        }
        cout << endl;
    }

    return 0;
}
