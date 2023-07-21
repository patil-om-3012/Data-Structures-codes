//articualtion pts in a graph

#include<bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int v;
    vector<vector<int>> adjList;

    Graph(int v)
    {
        this->v = v;
        adjList.resize(v);
    }

    void addEdge(int u,int v);
    void cutVertex();
    void cutVertexDFS(int src,int parent,vector<int> &visited,int &time,vector<int> &discoveryTime,vector<int> &lowestTime,vector<int> &ans);
};

void Graph::addEdge(int u,int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::cutVertexDFS(int src,int parent,vector<int> &visited,int &time,vector<int> &discoveryTime,vector<int> &lowestTime,vector<int> &ans)
{
    visited[src] = 1;
    time++;
    discoveryTime[src] = lowestTime[src] = time;
    int child = 0;

    for(auto neighbour:adjList[src])
    {
        if(!visited[neighbour])
        {
            cutVertexDFS(neighbour,src,visited,time,discoveryTime,lowestTime,ans);
            lowestTime[src] = min(lowestTime[src],lowestTime[neighbour]);
            if(discoveryTime[src] <= lowestTime[neighbour] && parent != -1)
            {
                ans.push_back(src);
            }
            child++;
        }

        else if(neighbour != parent)
        {
            lowestTime[src] = min(lowestTime[src],discoveryTime[neighbour]);
        }
    }

    if(parent == -1 && child > 1)
    {
        ans.push_back(src);
    }
}

void Graph::cutVertex()
{
    int time = 0;
    vector<int> visited(v,0);
    vector<int> discoveryTime(v,0);
    vector<int> lowestTime(v,0);
    vector<int> ans;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            cutVertexDFS(i,-1,visited,time,discoveryTime,lowestTime,ans);
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
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

    g.cutVertex();
}