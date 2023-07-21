//check if a path exists from source s to destination d in a given graph

#include<bits/stdc++.h>

using namespace std;

class Graph
{
    public:

        int v;
        vector<list<int>> adjList; //adjlist is pointer variable

        void addEdge(int u,int v);
        int pathExists(int src,int dest);

        Graph(int v)
        {
            this->v = v;
            adjList.resize(v);
        }
    
};

int Graph::pathExists(int src,int dest)
{
    vector<int> visited(v,0);

    visited[src] = 1;

    if(src == dest)
    {
        return 1;
    }

    for(auto x:adjList[src])
    {
        if(x && !visited[x]) //to ensure that our src node is not out of bounds
        {
            if(pathExists(x,dest)){return 1;}
        }
    }

    return 0;

}

void Graph::addEdge(int u,int v)
{
    adjList[u].push_back(v); //for an undirected graph one more step required
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
    g.addEdge(4,5);
    cout << g.pathExists(0,4);
    return 0;
}