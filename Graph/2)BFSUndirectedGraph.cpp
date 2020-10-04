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
//this is sufficient for graph with one whole component
void BFS(vector<int> adj[], int v, int s)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto x : adj[u])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    cout << endl;
}
//if graph is disconnected & no source is given
void BFS2(vector<int> adj[], int s, bool visited[])
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto x : adj[u])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    cout << endl;
}
//count is used to print no. of connected components
int BFSDisconnected(vector<int> adj[], int v)
{
    int count = 0;
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            BFS2(adj, i, visited);
            count++;
        }
    }
    return count;
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
    BFS(adj, v, 0);
    cout << BFSDisconnected(adj, v);
    return 0;
}