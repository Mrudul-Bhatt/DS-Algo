//for undirected graph
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void addEdgeDir(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
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
bool DFS(vector<int> adj[], int s, bool visited[], bool recStack[])
{
    visited[s] = true;
    recStack[s] = true;
    for (auto x : adj[s])
    {
        if (visited[x] == false && DFS(adj, x, visited, recStack))
            return true;
        else if (recStack[x] == true)
            return true;
    }
    recStack[s] = false;
    return false;
}
bool DFSDetectCycle(vector<int> adj[], int v)
{
    bool visited[v];
    bool recStack[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            if (DFS(adj, i, visited, recStack))
                return true;
    return false;
}

int main()
{
    //cycle detection in directed graph can also be
    //done using topological sorting using bsf (kahns algo)
    int v = 3;
    vector<int> adj[v];
    addEdgeDir(adj, 0, 1);
    addEdgeDir(adj, 1, 2);
    addEdgeDir(adj, 2, 0);
    printGraph(adj, v);
    cout << DFSDetectCycle(adj, v);
    return 0;
}