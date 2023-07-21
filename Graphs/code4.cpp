//Dijkstra's Algorithm

#include<bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int v;
    vector<vector<pair<int,int>>> adjList;

    Graph(int vertices)
    {
        this->v = vertices;
        this->adjList.resize(v);
    }

    void addEdge(int u,int v,int w);

    void Dijkstra(int src);
};

void Graph::addEdge(int u,int v,int w)
{
    adjList[u].push_back({v,w});
    adjList[v].push_back({u,w});
}

void Graph::Dijkstra(int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src}); //elemnts in pq processed on basis of first value in the pair
    vector<int> distance(v,INT_MAX);
    distance[src] = 0;

    while(!pq.empty())
    {
        int cur = pq.top().second;
        pq.pop();

        for(auto x:adjList[cur])
        {
            if(distance[x.first] > distance[cur] + x.second)
            {
                distance[x.first] = distance[cur] + x.second;
                pq.push({distance[x.first],x.first});
            }
        }
    }

    for(auto dist:distance)
    {
        cout << dist << endl;
    }
}

int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.Dijkstra(0);
}