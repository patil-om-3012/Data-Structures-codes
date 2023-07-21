// cycle detection in undirected graph

#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int v;
    vector<vector<int>> adjList;
    vector<bool> visited;

    void addEdge(int u, int w);
    void DFS();
    void DFSUtil(int x, int parent);

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
    adjList[w].push_back(u);
}

// Recursive DFS
void Graph::DFSUtil(int x, int parent)
{
    visited[x] = true;

    for (auto n : adjList[x])
    {
        if (!visited[n])
        {
            DFSUtil(n, x);
        }
        else if (n != parent) //if adjancent is visisted and is not a parent , it indicates a cycle
        {
            cout << "Cycle deteced";
            break;
        }
    }

    return;
}

void Graph::DFS()
{
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFSUtil(i, -1);
        }
    }
}

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(2,6);
    g.addEdge(0,3);

    Graph g1(2);
    g1.addEdge(0,1);
    g1.addEdge(1,0);

    Graph g2(3);
    g2.addEdge(0,1);
    g2.addEdge(1,2);

    //g.DFS();
    g1.DFS();
    //g2.DFS();
}