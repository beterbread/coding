/*
    Find the topological sort of a graph
    Time complexity O(m*log(n)) - n = # of nodes, m = # of edges 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int numNodes, vector<vector<int>>& edges) {
    vector<int> indegree(numNodes, 0);
    vector<vector<int>> adjList(numNodes);
    
    // Build the graph and compute indegree of each node
    for (auto& edge : edges) {
        adjList[edge[0]].push_back(edge[1]);  // Directed edge from edge[0] to edge[1]
        indegree[edge[1]]++;
    }
    
    // Queue for nodes with 0 indegree
    queue<int> q;
    for (int i = 0; i < numNodes; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    // List to store the topological order
    vector<int> topoOrder;
    
    // Perform topological sort
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);
        
        for (int neighbor : adjList[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    // If the topological sort includes all nodes, return it
    if (topoOrder.size() == numNodes) {
        return topoOrder;
    }
    
    // If the graph has a cycle, return an empty vector
    return {};
}

int main() {
    int numNodes = 6;
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    
    vector<int> result = topologicalSort(numNodes, edges);
    
    if (!result.empty()) {
        cout << "Topological Order: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "Graph has a cycle!" << endl;
    }
    
    return 0;
}