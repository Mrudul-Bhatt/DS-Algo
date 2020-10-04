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
        cout << i;
        for (auto x : adj[i])
            cout << "-> " << x;
        cout << endl;
    }
}
//Topological sorting using BSF (Kahns Algo), we can also
//use this to detect cyclic or acyclic graph as this algo
//works only for directed acyclic graphs (DAG)
void BFS(vector<int> adj[], int v)
{
    vector<int> indegree(v, 0);
    int count = 0;
    // for (auto i = indegree.begin(); i != indegree.end(); i++)
    //     cout << indegree[*i] << " ";
    // cout << endl;

    for (int i = 0; i < v; i++)
        for (auto x : adj[i])
            indegree[x]++;
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (indegree[i] == 0)
            q.push(i);
    vector<int> output;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        output.push_back(u);
        for (auto x : adj[u])
            if (--indegree[x] == 0)
                q.push(x);
        count++;
    }
    if (count != v)
    {
        cout << "Graph consists a cycle" << endl;
        return;
    }
    for (auto x : output)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int v = 3;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    printGraph(adj, v);
    BFS(adj, v);
    return 0;
}