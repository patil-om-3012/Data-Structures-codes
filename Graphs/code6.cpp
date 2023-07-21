#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

class Compare {
public:
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};

void addEdge(Graph& graph, int u, int v, int weight) {
    graph[u].emplace_back(v, weight);
    graph[v].emplace_back(u, weight);
}

void primMST(const Graph& graph, int startVertex) {
    int V = graph.size();
    vector<bool> visited(V, false);
    vector<pii> parent(V, {-1, -1});
    priority_queue<pii, vector<pii>, Compare> pq;
    pq.push(make_pair(startVertex, 0));

    while (!pq.empty()) {
        int u = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        if (parent[u].first != -1) {
            cout << "Included edge: " << parent[u].first << " - " << u << " with weight " << parent[u].second << endl;
        }

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!visited[v]) {
                pq.push(make_pair(v, w));
                parent[v] = make_pair(u, w);
            }
        }
    }
}

int main() {
    int V = 9; // Number of vertices
    Graph graph(V);

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    int startVertex = 0; // Starting vertex for MST

    cout << "Prim's Minimum Spanning Tree:" << endl;
    primMST(graph, startVertex);

    return 0;
}
