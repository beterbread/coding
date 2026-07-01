#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> par,sz;
    int comps,mx;
    DSU(int n) : par(n+1), sz(n+1,1), comps(n), mx(1) {
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int x) {
        if (par[x] == x) return x;
        par[x] = find(par[x]);
        return par[x];
    }

    bool unite(int x, int y) {
        int x_root = find(x), y_root = find(y);
        if (x_root == y_root) return false;
        if (sz[x_root] < sz[y_root]) swap(x_root,y_root);
        sz[x_root] += sz[y_root];
        par[y_root] = x_root;
        comps--;
        mx = max(mx,sz[x_root]);
        return true;
    }

    void query() {
        cout << comps << ' ' << mx << '\n';
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        int x,y; cin >> x >> y;
        dsu.unite(x,y);
        dsu.query();
    }
}