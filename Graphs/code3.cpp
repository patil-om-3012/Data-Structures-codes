#include<bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int v;
    vector<vector<int>> adjList;
    vector<int> indegree;

    Graph(int v)
    {
        this->v = v;
        adjList.resize(v);
        indegree.resize(v);
    }

    void addEdge(int u, int v);
    void topoSort();
};

void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v);
    indegree[v] ++ ;
}

void Graph::topoSort()
{
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int temp = q.front();
        ans.push_back(temp);
        q.pop();

        for (auto& x : adjList[temp])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }

    if (ans.size() == v)
    {
        for (int order : ans)
        {
            cout << order << " ";
        }

        return;
    }

    cout << "Topological sort doesn't exist" << " ";
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topoSort();
}
