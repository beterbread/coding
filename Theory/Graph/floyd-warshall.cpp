/*
    Floyd-Warshall algorithm, finds all shortest paths between nodes in a single run
    Time complexity O(n^3) - n = # of nodes
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; // A large value representing infinity

void floydWarshall(int numNodes, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph; // Copy the graph to initialize distances

    // Floyd-Warshall algorithm
    for (int k = 0; k < numNodes; k++) {
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Output the distances
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cout << "Distance from node " << i << " to node " << j << " is ";
            if (dist[i][j] == INF) {
                cout << "INF" << endl;
            } else {
                cout << dist[i][j] << endl;
            }
        }
        cout << endl;
    }
}

int main() {
    int numNodes = 4;
    vector<vector<int>> graph = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    cout << "Floyd-Warshall algorithm results:" << endl;
    floydWarshall(numNodes, graph);

    return 0;
}