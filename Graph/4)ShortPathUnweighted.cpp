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
        cout << i;
        for (auto x : adj[i])
            cout << "-> " << x;
        cout << endl;
    }
}
void BFS(vector<int> adj[], int v, int s)
{
    int dist[v];
    fill_n(dist, v, INT_MIN);
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto x : adj[u])
        {
            if (visited[x] == false)
            {
                dist[x] = dist[u] + 1;
                visited[x] = true;
                q.push(x);
            }
        }
    }
    for (int i = 0; i < v; i++)
        cout << dist[i] << " ";
}

int main()
{
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, v);
    BFS(adj, v, 0);
    return 0;
}