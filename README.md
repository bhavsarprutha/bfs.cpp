# bfs.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


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

    // Recursive BFS traversal
    void BFSUtil(queue<int>& q, unordered_set<int>& visited) {
        if (q.empty())
            return;

        int current = q.front();
        q.pop();
        cout << current << " ";
        
        for (int neighbor : adj[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }

        BFSUtil(q, visited); // Recursive call
    }

    // Function to perform BFS traversal
    void BFS() {
        unordered_set<int> visited;
        queue<int> q;

        for (int i = 0; i < V; ++i) {
            if (visited.find(i) == visited.end()) {
                visited.insert(i);
                q.push(i);
                BFSUtil(q, visited);
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

    cout << "Breadth First Traversal starting from vertex 0:\n";
    g.BFS();
    cout << endl;

    return 0;
}
