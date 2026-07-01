/*
    Breadth-first search, explores layer by layer
    Uses Queue, O(n + m) - n = # of nodes, m = # of edges
*/

#include <bits/stdc++.h>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        cout << u << " ";    // Process

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int numNodes = 6;

    vector<vector<int>> adjList(numNodes);
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1, 5};
    adjList[4] = {1, 2, 5};
    adjList[5] = {3, 4};

    int startNode = 0;

    cout << "BFS starting from node " << startNode << ": ";
    bfs(startNode, adjList);
    cout << endl;

    return 0;
}