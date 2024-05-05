#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

class Graph {
    int V;
    vector<vector<int>> graph;

public:
    Graph(int V) : V(V) {
        graph.resize(V, vector<int>(V, 0));
    }

    void addEdge(int src, int dest, int weight) {
        graph[src][dest] = weight;
        graph[dest][src] = weight; // Assuming undirected graph
    }

    void DijkstraMST(int src) {
        vector<bool> visited(V, false);
        vector<int> distance(V, INF);
        vector<int> parent(V, -1);

        distance[src] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = -1;
            for (int v = 0; v < V; ++v) {
                if (!visited[v] && (u == -1 || distance[v] < distance[u]))
                    u = v;
            }

            visited[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!visited[v] && graph[u][v] != 0 && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                    parent[v] = u;
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }

        cout << "Edges in the Minimal Spanning Tree:" << endl;
        for (int i = 0; i < V; ++i) {
            if (i != src)
                cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        }
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    graph.DijkstraMST(0);

    return 0;
}
