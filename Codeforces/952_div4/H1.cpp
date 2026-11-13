#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   

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

void solve() {
    int n,m; cin >> n >> m;
    vector<string> a(n);
    FOR(i,n) cin >> a[i];
    DSU dsu(n*m);
    auto id = [&](int i, int j) -> int {
        return m*i+j;
    };
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '#') continue;
            for (const auto& [x,y] : dir) {
                int x2 = i+x, y2 = j+y;
                if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && a[x2][y2] == '#') {
                    dsu.unite(id(i,j),id(x2,y2));
                }
            }
        }
    }
    map<int,int> map; // par, last used
    int res = 0;
    // try rows
    for (int i = 0; i < n; ++i) {
        int pos = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '#') pos++;
            if (a[i][j] == '#') {
                int par = dsu.find(id(i,j));
                if (map.find(par) == map.end() || map[par] != i) {
                    pos += dsu.sizes[par];
                    map[par] = i;
                }
            }
            if (i-1 >= 0 && a[i-1][j] == '#') {
                int par = dsu.find(id(i-1,j));
                if (map.find(par) == map.end() || map[par] != i) {
                    pos += dsu.sizes[par];
                    map[par] = i;
                }
            }
            if (i+1 < n && a[i+1][j] == '#') {
                int par = dsu.find(id(i+1,j));
                if (map.find(par) == map.end() || map[par] != i) {
                    pos += dsu.sizes[par];
                    map[par] = i;
                }
            }
        }
        res = max(res,pos);
    }
    // try cols
    map = {};
    for (int j = 0; j < m; ++j) {
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i][j] != '#') pos++;
            if (a[i][j] == '#') {
                int par = dsu.find(id(i,j));
                if (map.find(par) == map.end() || map[par] != j) {
                    pos += dsu.sizes[par];
                    map[par] = j;
                }
            }
            if (j-1 >= 0 && a[i][j-1] == '#') {
                int par = dsu.find(id(i,j-1));
                if (map.find(par) == map.end() || map[par] != j) {
                    pos += dsu.sizes[par];
                    map[par] = j;
                }
            }
            if (j+1 < m && a[i][j+1] == '#') {
                int par = dsu.find(id(i,j+1));
                if (map.find(par) == map.end() || map[par] != j) {
                    pos += dsu.sizes[par];
                    map[par] = j;
                }
            }
        }
        res = max(res,pos);
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
