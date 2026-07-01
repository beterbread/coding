/*
    Dijkstra's Algorithm, used to find shortest paths for graphs w/o negative weights
    More efficient than Bellman-Ford Algorithm, but can't have negative weights
    Time complexity O(n + m*log(m)) - n = # of nodes, m = # of edges
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; // A large value representing infinity

void dijkstra(int startNode, int numNodes, const vector<vector<pair<int,int>>>& adj) {
    vector<int> distance(numNodes, INF);
    vector<bool> processed(numNodes, false);
    // Stores weight, node and spits out smallest values first
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 

    distance[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int a = pq.top().second; // a = node
        pq.pop();
        if (processed[a]) continue;
        processed[a] = true;

        for (const auto& x : adj[a]) { // Go through the neighbors of a
            auto [b, w] = x; // b = neighbor, w = weight from a to b
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                pq.push({distance[b], b});
            }
        }
    }

    // Output the distances
    for (int i = 0; i < numNodes; i++) {
        cout << "Distance from node " << startNode << " to node " << i << " is ";
        if (distance[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }
}

int main() {
    int numNodes = 5;
    vector<vector<pair<int,int>>> adj(numNodes);
    
    adj[0].push_back({1, 6});
    adj[0].push_back({2, 7});
    adj[1].push_back({2, 8});
    adj[1].push_back({3, 5});
    adj[1].push_back({4, 4});
    adj[2].push_back({3, 3});
    adj[2].push_back({4, 9});
    adj[3].push_back({1, 2});
    adj[4].push_back({3, 7});

    int startNode = 0;

    cout << "Dijkstra's algorithm starting from node " << startNode << ":" << endl;
    dijkstra(startNode, numNodes, adj);

    return 0;
}
