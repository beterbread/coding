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

void solve() {
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    FOR(i,n-1) {
        int x,y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    // cout << "STARTING\n";
    vector<bool> visited(n+1,false);
    vector<bool> contains(n+1,false);
    contains[n] = true;
    auto contains_n = [&](int x, auto&& contains_n) -> bool {
        if (visited[x]) return false;
        visited[x] = true;
        for (int y : adj[x]) {
            bool joe = contains_n(y,contains_n);
            contains[x] = (joe ? true : contains[x]);
        }
        // cout << x << ' ' << contains[x] << '\n';
        return contains[x];
    };
    contains_n(1,contains_n);

    fill(all(visited),false);
    vector<int> dist(n+1,-1);
    auto dfs_from_n = [&](int x, int cur_dist, auto&& dfs_from_n) -> void {
        if (visited[x]) return;
        visited[x] = true;
        dist[x] = cur_dist;
        for (int y : adj[x]) {
            dfs_from_n(y,cur_dist+1,dfs_from_n);
        }
    };
    dfs_from_n(n,0,dfs_from_n);

    fill(all(visited),false);
    set<int> set;
    auto dfs = [&](int x, auto&& dfs) -> void {
        if (visited[x]) return;
        visited[x] = true;
        set.insert(x);
        for (int y : adj[x]) {
            if (y == 1) continue; // DON'T GO BACK UP
            dfs(y,dfs);
        }
    };

    int joe = -1;
    for (int y : adj[1]) {
        if (contains[y]) {
            joe = y;
            dfs(y,dfs);
            break;
        }
    }
    // cout << "SET\n";
    // each(x,set) cout << x << ' ' << dist[x] << '\n';

    int res = dist[joe];
    FOR(i,m) {
        int x; cin >> x;
        if (set.find(x) != set.end()) {
            res = max(res,dist[x]);
        }
    }
    cout << res+1 << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
