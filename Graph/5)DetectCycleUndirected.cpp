//for undirected graph
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; ++i)
    {
        cout << "\n Adjacency list of vertex "
             << i << "\n head ";
        for (auto x : adj[i])
            cout << "-> " << x;
        cout << endl;
    }
}
bool DFS(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (auto x : adj[s])
    {
        if (visited[x] == false)
        {
            if (DFS(adj, x, visited, s) == true)
                return true;
        }
        else if (x != parent)
            return true;
    }
    return false;
}
bool DFSDetectCycle(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            if (DFS(adj, i, visited, -1) == true)
                return true;
    return false;
}

int main()
{
    int v = 3;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    printGraph(adj, v);
    cout << DFSDetectCycle(adj, v);
    return 0;
}