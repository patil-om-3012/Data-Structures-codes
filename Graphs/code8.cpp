#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int v;
    int count;
    vector<vector<int>> adjList;

    Graph(int v)
    {
        this->v = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v);
    void pathExists(int src, int dest);
};

void Graph::pathExists(int src, int dest)
{
    vector<int> visited(v, 0);

    visited[src] = 1;

    if (src == dest)
    {
        count++;
    }
    else
    {

        for (auto x : adjList[src])
        {
            if (x && !visited[x]) // to ensure that our src node is not out of bounds
            {
                pathExists(x, dest);
            }
        }
    }

    visited[src] = 0; //the backtracking step (for every possible vertex in path, mark it unvisisted to reexplore further unexplored and unvisisted routes)
}

void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v); // for an undirected graph one more step required
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(4, 5);
    g.pathExists(0, 4);
    cout << g.count;
    return 0;
}