/*
    Depth-first Search, explores as far as possible
    Uses Stack, O(n + m) - n = # of nodes, m = # of edges
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    stack<int> st;

    visited[start] = true;  
    st.push(start);

    while (!st.empty()) {
        int u = st.top(); 
        st.pop();
        cout << u << " "; // Process

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

void dfs(int s, const vector<vector<int>>& adj, vector<bool>& visited) {
    if (visited[s]) {
        return;
    }
    cout << s << " "; // Process
    visited[s] = true;
    for (const int& u : adj[s]) {
        dfs(u, adj, visited);
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

    cout << "Iterative DFS starting from node " << startNode << ": ";
    dfs(startNode, adjList); 
    
    cout << endl;

    vector<bool> visited(adjList.size(), false);
    cout << "Recursive DFS starting from node " << startNode << ": ";
    dfs(startNode, adjList, visited);
    cout << endl;

    return 0;
}