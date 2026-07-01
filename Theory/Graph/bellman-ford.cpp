/*
    Bellman-Ford Algorithm, used to find shortest paths for graphs with negative weights
    Can detect negative cycles, run algorithm for n rounds instead of n - 1 and 
    if nth round reduces any distance, the graph contains a negative cycle
    Time complexity O(n * m) - n = # of nodes, m = # of edges
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; // A large value representing infinity

void bellmanFord(int startNode, int numNodes, const vector<tuple<int, int, int>>& edges) {
    vector<int> distance(numNodes, INF);
    distance[startNode] = 0;

    for (int i = 1; i <= numNodes - 1; i++) { // Runs n - 1 times
        for (const auto& e : edges) { // Go through all edges and update shortest paths
            int a, b, w;
            tie(a, b, w) = e; // Assign a, b, w with tuple e
            distance[b] = min(distance[b], distance[a] + w);
        }
    }

    // Output the distances
    for (int i = 0; i < numNodes; i++) {
        cout << "Distance from node " << startNode << " to node " << i << " is ";
        if (distance[i] == INF) { // No path to node
            cout << "INF" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }
}

int main() {
    int numNodes = 5;
    vector<tuple<int, int, int>> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 3, 7}
    };

    int startNode = 0;

    cout << "Bellman-Ford starting from node " << startNode << ":" << endl;
    bellmanFord(startNode, numNodes, edges);

    return 0;
}
