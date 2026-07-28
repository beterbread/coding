#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parents;
    vector<int> sizes;

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
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,x,y; cin >> n >> x >> y;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        DSU dsu(n);
        for (int i = 0; i < n; ++i) {
            if (i+x < n) {
                dsu.unite(i,i+x);
            }
            if (i+y < n) {
                dsu.unite(i,i+y);
            }
        }
        bool res = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] != i+1) {
                if (dsu.find(i) != dsu.find(a[i]-1)) {
                    res = false;
                    break;
                }
            }
        }
        cout << (res ? "YES" : "NO") << '\n';
    }
}