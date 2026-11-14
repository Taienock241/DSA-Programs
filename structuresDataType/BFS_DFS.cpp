#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Breadth First Search
bool BFS(vector<vector<int>>& graph, int s, int t) {

    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {

        int current = q.front();
        q.pop();

        if (current == t)
            return true;

        for (int neighbor : graph[current]) {

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false;
}

// Depth First Search
bool DFS(vector<vector<int>>& graph,
         vector<bool>& visited,
         int current,
         int t) {

    visited[current] = true;

    if (current == t)
        return true;

    for (int neighbor : graph[current]) {

        if (!visited[neighbor]) {

            if (DFS(graph, visited, neighbor, t))
                return true;
        }
    }

    return false;
}

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V);

    cout << "Enter the edges:\n";

    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int s, t;

    cout << "Enter source and target: ";
    cin >> s >> t;

    if (BFS(graph, s, t))
        cout << "BFS: Connection exists\n";
    else
        cout << "BFS: No connection exists\n";

    vector<bool> visited(V, false);

    if (DFS(graph, visited, s, t))
        cout << "DFS: Connection exists\n";
    else
        cout << "DFS: No connection exists\n";
        cout << "DFS: No connection exists\n";

    return 0;
}