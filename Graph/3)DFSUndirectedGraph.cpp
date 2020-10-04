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
void DFS(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (auto x : adj[s])
        if (visited[x] == false)
            DFS(adj, x, visited);
}
//1 connected component and source vertice given
void DFSConnected(vector<int> adj[], int v, int s)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    DFS(adj, s, visited);
    cout << endl;
}
//find number of connected componets and no source vertice given
void DFSDisconnected(vector<int> adj[], int v)
{
    int count = 0;
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            DFS(adj, i, visited);
            count++;
        }
    }
    cout << endl
         << count << endl;
}

int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    //addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    //addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    //addEdge(adj, 3, 4);
    printGraph(adj, v);
    DFSConnected(adj, v, 0);
    DFSDisconnected(adj, v);
    return 0;
}