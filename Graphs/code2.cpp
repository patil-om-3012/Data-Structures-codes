// DFS traversal of a graph
// handles disconnected graph

#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int v;
    vector<list<int>> adjList;
    vector<bool> visited;

    void addEdge(int u, int w);
    void DFS();
    void DFSUtil(int x);

    Graph(int v)
    {
        this->v = v;
        adjList.resize(v);
        visited.resize(v, false);
    }
};

void Graph::addEdge(int u, int w)
{
    adjList[u].push_back(w);
}

// Recursive DFS
void Graph::DFSUtil(int x)
{
    visited[x] = true;
    cout << x << endl;

    for (auto it = adjList[x].begin(); it != adjList[x].end(); ++it)
    {
        
        if (!visited[*(it)])
        {
            DFSUtil(*(it));
        }
    }
}

void Graph::DFS()
{
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFSUtil(i);
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS();
}