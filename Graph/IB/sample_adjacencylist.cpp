#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    // Create an adjacency list
    vector<vector<int>> adjList(numVertices);

    cout << "Enter the edges (format: vertex1 vertex2):" << endl;
    int u, v;
    for (int i = 0; i < numEdges; i++) {
        cin >> u >> v;

        // Assuming 0-based indexing for vertices
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For an undirected graph, we add both edges u-v and v-u
    }

    // Printing the adjacency list
    cout << "The adjacency list of the graph:" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
