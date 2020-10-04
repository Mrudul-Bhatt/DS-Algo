//for undirected graph
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
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
void DFS(vector<int> adj[], int s, bool visited[], stack<int> &st)
{
    visited[s] = true;
    for (auto x : adj[s])
        if (visited[x] == false)
            DFS(adj, x, visited, st);
    st.push(s);
}

void TopologicalSort_DFS(vector<int> adj[], int v, vector<int> &tsort)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    stack<int> st;
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            DFS(adj, i, visited, st);
    while (!st.empty())
    {
        tsort.push_back(st.top());
        st.pop();
    }

    cout << endl;
}
void ShortPathDAG(vector<int> adj[], int v, int s)
{
    int dist[v];
    fill_n(dist, v, INT_MAX);
    dist[s] = 0;
    vector<int> tsort;
    TopologicalSort_DFS(adj, v, tsort);
    for (int i = 0; i < v; i++)
    {
        int u = tsort[i];
        for (auto x : adj[u])
            if (dist[x] > dist[u] + 1)
                dist[x] = dist[u] + 1;
    }
    for (int i = 0; i < v; i++)
        cout << dist[i] << " ";
}

int main()
{
    int v = 3;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    printGraph(adj, v);
    ShortPathDAG(adj, v, 0);
    return 0;
}