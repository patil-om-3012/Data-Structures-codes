#include<bits/stdc++.h>

using namespace std;

//relaxing an edge first time means shortest path from source to nay vertex with atmost one edge, 2nd time means atmost 2 edges in path
//Thus any path from source to farthest vertex can have atmost V-1 edges. vth iteration is just to detect a -ve cycle //see Ga Sm on YT 

class Graph
{
public:
    int v;
    int e;
    vector<pair<int,pair<int,int>>> edges; //edgeWeight -> {src,dest}

    Graph(int v,int e)
    {
        this->v=v;
        this->e=e;
        //edges.resize(e);
    }

    void addEdge(int x,int y,int z);

    //void addEdge(int x,int y,int z);
    void bellmanFord(int src);
};

void Graph::addEdge(int x,int y,int z)
{
    edges.push_back({z,{x,y}});
}

void Graph::bellmanFord(int src)
{
    vector<int> distance(v,INT_MAX);
    distance[src] = 0;

    for(int i=0;i<=v-1;i++)
    {
        for(int i=0;i<e;i++)
        {
            int src = edges[i].second.first;
            int dest = edges[i].second.second;
            int weight = edges[i].first;

            if(distance[src]!= INT_MAX && distance[dest] > distance[src] + weight)
            {
                distance[dest] = distance[src] + weight;
            }
        }
    }

    for(int i=0;i<e;i++)
    {
        int src = edges[i].second.first;
        int dest = edges[i].second.second;
        int weight = edges[i].first;

        if(distance[src] != INT_MAX && distance[dest] > distance[src] + weight)
        {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    for(int i=0;i<v;i++)
    {
        cout << "Distance[" << i << "]" << "= " << distance[i] << endl; 
    }

    return;
}

int main()
{
    Graph g(5,8);
    g.addEdge(0,1,-1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,2);
    g.addEdge(3,2,5);
    g.addEdge(3,1,1);
    g.addEdge(4,3,-3);

    g.bellmanFord(0);

    return 0;
}