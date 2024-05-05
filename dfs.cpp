#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Class to represent an undirected graph
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); // For undirected graph
    }

    // Recursive DFS traversal
    void DFSUtil(int v, unordered_set<int>& visited) {
        visited.insert(v);
        cout << v << " ";
        
        for (int neighbor : adj[v]) {
            if (visited.find(neighbor) == visited.end()) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // Function to perform DFS traversal
    void DFS() {
        unordered_set<int> visited;

        for (int i = 0; i < V; ++i) {
            if (visited.find(i) == visited.end()) {
                DFSUtil(i, visited);
            }
        }
    }
};

int main() {
    Graph g(6); // Graph with 6 vertices

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "Depth First Traversal starting from vertex 0:\n";
    g.DFS();
    cout << endl;

    return 0;
}
