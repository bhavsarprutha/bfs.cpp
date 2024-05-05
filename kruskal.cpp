#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int V) : V(V) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    // Find set of an element i
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    // Perform union of two sets
    void Union(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    // Greedy search algorithm for Kruskal's Minimal Spanning Tree
    void KruskalMST() {
        vector<Edge> result(V - 1);

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        vector<int> parent(V, -1);

        int e = 0; // An index variable, used for result[]
        int i = 0; // An index variable, used for sorted edges
        while (e < V - 1 && i < edges.size()) {
            Edge next_edge = edges[i++];

            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            if (x != y) {
                result[e++] = next_edge;
                Union(parent, x, y);
            }
        }

        cout << "Edges in the Minimal Spanning Tree:" << endl;
        for (int j = 0; j < e; ++j)
            cout << result[j].src << " - " << result[j].dest << " : " << result[j].weight << endl;
    }
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    graph.KruskalMST();

    return 0;
}
