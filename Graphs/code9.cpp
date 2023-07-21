// find bridge edges in graph

#include <bits/stdc++.h>

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

    void addEdge(int u, int v);
    void bridgeEdges();
    void bridgeDFS(int src,int parent,int &time,vector<int> &visited,vector<int> &discoveryTime,vector<int> &lowestTime,vector<vector<int>> &brdiges);
};

void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::bridgeDFS(int src,int parent,int &time,vector<int> &visited,vector<int> &discoveryTime,vector<int> &lowestTime,vector<vector<int>> &bridges)
{ 
    visited[src] = true;
    time++;
    discoveryTime[src] = lowestTime[src] = time;

    for(auto neighbour:adjList[src])
    {
        if(!visited[neighbour])
        {
            bridgeDFS(neighbour,src,time,visited,discoveryTime,lowestTime,bridges);
            lowestTime[src] = min(lowestTime[src],lowestTime[neighbour]);
            if(discoveryTime[src] < lowestTime[neighbour])
            {
                bridges.push_back({src,neighbour});
            }
        }
        else if(neighbour != parent)
        {
            lowestTime[src] = min(lowestTime[src],discoveryTime[neighbour]);
        }
    }
}

void Graph::bridgeEdges()
{
    vector<int> visited(v,0);
    vector<int> discoveryTime(v,0);
    vector<int> lowestTime(v,0);
    vector<vector<int>> bridges;

    int time = 0;

    for(int i=0;i<v;i++)
    {
        if(!visited[v])
        {
            bridgeDFS(v,-1,time,visited,discoveryTime,lowestTime,bridges);
        }
    }
}

int main()
{

}