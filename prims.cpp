#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Represents infinity

// Define a structure to represent an edge in the graph
struct Edge {
    int to;
    int weight;

    Edge(int to, int weight) : to(to), weight(weight) {}
};

// Function to find the minimal spanning tree using Prim's algorithm
void primMST(const vector<vector<Edge>>& graph, int start) {
    int V = graph.size(); // Number of vertices
    vector<bool> visited(V, false); // Tracks visited vertices
    vector<int> minDist(V, INF); // Tracks minimum distance to each vertex
    vector<int> parent(V, -1); // Tracks parent of each vertex in MST

    minDist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (!visited[v] && weight < minDist[v]) {
                parent[v] = u;
                minDist[v] = weight;
                pq.push({minDist[v], v});
            }
        }
    }

    // Print the edges of the minimal spanning tree
    cout << "Minimal Spanning Tree Edges:" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<Edge>> graph(V); // Adjacency list representation of the graph

    // Add edges to the graph
    graph[0].emplace_back(1, 2);
    graph[0].emplace_back(3, 6);
    graph[1].emplace_back(0, 2);
    graph[1].emplace_back(3, 8);
    graph[1].emplace_back(2, 3);
    graph[2].emplace_back(1, 3);
    graph[2].emplace_back(4, 5);
    graph[3].emplace_back(0, 6);
    graph[3].emplace_back(1, 8);
    graph[3].emplace_back(4, 9);
    graph[4].emplace_back(2, 5);
    graph[4].emplace_back(3, 9);

    // Start Prim's algorithm from vertex 0
    primMST(graph, 0);

    return 0;
}
