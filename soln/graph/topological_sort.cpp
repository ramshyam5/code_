#include <bits/stdc++.h>
using namespace std;
class graph
{
    static int count;
    int *in_degree;

public:
    graph(int n)
    {
        in_degree = new int[n];
        for (int i = 0; i < n; i++)
        {
            in_degree[i] = 0;
        }
    }
    void edge(vector<int> adj[], int u, int v)
    {
        adj[u].push_back(v);
        count++;
        in_degree[v]++;
    }
    ~graph()
    {
        delete[] in_degree;
    }
    void getcount()
    {
        cout << count;
    }
    bool iscycle(int src, vector<int> adj[], vector<bool> &visited, vector<int> &stack)
    {
        stack[src] = true;
        if (!visited[src])
        {
            visited[src] = true;
            for (auto i : adj[src])
            {
                if (!visited[src] and iscycle(i, adj, visited, stack))
                {
                    return true;
                }
                if (stack[i])
                    return true;
            }
        }
        else
        {
            stack[src] = false;
            return false;
        }
        return false;
    }
    void tps(vector<int> adj[], int n)
    {
        vector<int> result;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (int neighbor : adj[node])
            {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        cout << "\nThe Prerequisites of courses are given in following order:";
        for (int ele : result)
        {
            cout << ele << "-->";
        }
    }
    void getcredit(vector<int> &credit)
    {
        int total_credit = 0;
        for (int ele : credit)
        {
            total_credit += ele;
        }
        cout << total_credit;
    }
};
int graph::count;
int main()
{
    int m, j, n, e, c;
    bool cycle = false;
    cout << "Enter the number of courses:";
    cin >> n;
    vector<int> adj[n];
    vector<int> stack(n, 0);
    vector<bool> visited(n, 0);
    vector<int> credit(n);
    graph g(n);
    cout << "\nEnter the number of prerequisites:";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "\nEnter the prerequisite and it’s corresponding courses:";
        cin >> m >> j;
        cout << "Enter the credit for each course:";
        cin >> c;
        credit.push_back(c);
        g.edge(adj, m, j);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] and g.iscycle(i, adj, visited, stack))
        {
            cycle = true;
        }
    }
    if (cycle)
    {
        cout << "\nThe graph is not a DAG";
    }
    else
    {
        cout << "\nThe total number of courses:";
        g.getcount();
        g.tps(adj, n);
        cout << "\nThe total credit is given by:";
        g.getcredit(credit);
    }
    return 0;
}