/*
    Prim's Algorithm, used to find the minimum spanning tree of a graph
    Time complexity O(n + m*log(n)) - n = # of nodes, m = # of edges
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; // A large value representing infinity

void prim(int numNodes, const vector<vector<pair<int, int>>>& adj) {
    vector<bool> inMST(numNodes, false); // Tracks nodes included in the MST
    vector<int> minEdge(numNodes, INF); // Minimum edge weight to connect to the MST
    vector<int> parent(numNodes, -1);   // Tracks the parent of each node in the MST
    int totalWeight = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    minEdge[0] = 0; // Start from node 0
    q.push({0, 0}); // Push {weight, node}

    while (!q.empty()) {
        int weight = q.top().first;
        int node = q.top().second;
        q.pop();

        if (inMST[node]) continue;
        inMST[node] = true;
        totalWeight += weight;

        for (const auto& edge : adj[node]) {
            int neighbor = edge.first;
            int edgeWeight = edge.second;

            if (!inMST[neighbor] && edgeWeight < minEdge[neighbor]) {
                minEdge[neighbor] = edgeWeight;
                parent[neighbor] = node;
                q.push({edgeWeight, neighbor});
            }
        }
    }

    // Output the MST
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < numNodes; i++) {
        if (parent[i] != -1) {
            cout << "Edge: " << parent[i] << " - " << i << ", Weight: " << minEdge[i] << endl;
        }
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main() {
    int numNodes = 5;
    vector<vector<pair<int, int>>> adj(numNodes);

    // Add edges (undirected graph)
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    cout << "Prim's algorithm for Minimum Spanning Tree:" << endl;
    prim(numNodes, adj);

    return 0;
}
