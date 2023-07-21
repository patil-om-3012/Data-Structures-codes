//BFS traversal of a Graph
//for a connected graph

#include<bits/stdc++.h>

using namespace std;

class Graph
{
    public:

    int vertices;
    vector<list<int>> adjList; //adjlist is pointer variable

    void addEdge(int u,int v);
    void BFS(int s);
    void BFSdisconnected(); // for a disconnected graph

    Graph(int v)
    {
        vertices = v;
        adjList.resize(vertices);
    }
    
};

void Graph::addEdge(int u,int v)
{
    adjList[u].push_back(v); //for an undirected graph one more step required
}

void Graph::BFS(int s)
{
    vector<bool> visited;
    visited.resize(vertices,false);
    queue<int> q;
    q.push(s);
    visited[s] = true; //a node is marked vsisted when it is pushed into the queue

    while(!q.empty())
    {
        int temp = q.front();
        cout<<temp<<endl;
        q.pop();
        visited[temp] = true;
        for(auto x: adjList[temp])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

void Graph::BFSdisconnected()
{
    vector<bool> visited;
    visited.resize(vertices,false);
    
    for(int i=0;i<vertices;i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty())
            {
                int temp = q.front();
                cout<< temp <<endl;
                q.pop();

                for(auto x:adjList[i])
                {
                    if(!visited[i])
                    {
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
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
    g.BFS(2);
}