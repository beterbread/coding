/*
    Kruskal's algorithm, used to find the minimum spanning tree of a graph
    Time complexity O(m*log(n)) - n = # of nodes, m = # of edges
*/

#include <bits/stdc++.h>
using namespace std;

class DSU {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DSU(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) parents[i] = i;
	}

	int find(int x) { 
		if (parents[x] == x) return x;
		parents[x] = find(parents[x]); // path compression
		return parents[x];
	}

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) return false;

		if (sizes[x_root] < sizes[y_root]) swap(x_root, y_root); // pick shorter tree to attach to the longer one
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	bool connected(int x, int y) { return find(x) == find(y); }
};

int kruskal(int numNodes, vector<vector<int>>& edges) {
    // Sort edges by weight ascending
    sort(edges.begin(), edges.end());

    DSU dsu(numNodes);
    int mstWeight = 0;
    int edgesUsed = 0;

    for (const auto& edge : edges) {
        int weight = edge[0];
        int node1 = edge[1];
        int node2 = edge[2];

        // Try to unite: if successful, include the edge in the MST
        if (dsu.unite(node1, node2)) {
            mstWeight += weight;
            edgesUsed++;
            if (edgesUsed == numNodes - 1) break;
        }
    }

    return mstWeight;
}

int main() {
    int numNodes = 6;
    vector<vector<int>> edges = {
        {1, 0, 1}, // {weight, node1, node2}
        {5, 0, 2},
        {3, 1, 2},
        {4, 1, 3},
        {2, 2, 3},
        {6, 3, 4},
        {7, 4, 5}
    };

    int mstWeight = kruskal(numNodes, edges);
    cout << "Total weight of the Minimum Spanning Tree: " << mstWeight << endl;
    return 0;
}