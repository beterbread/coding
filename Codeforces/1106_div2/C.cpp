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
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int par; cin >> par;
        par--; // zero indexing
        adj[par].pb(i);
    }
    int res = 0;
    unordered_map<int,int> map;
    auto dfs = [&](int x, int dist, auto&& dfs) -> void {
        map[dist]++;
        for (const auto& y : adj[x]) {
            dfs(y,dist+1,dfs);
        }
    };
    auto dfs2 = [&](int x, int dist, auto&& dfs2) -> void {
        // cout << x+1 << ' ' << adj[x].size() << ' ' << map[dist+1] << '\n';
        if (map.find(dist+1) != map.end() && adj[x].size() > 0 && adj[x].size() < map[dist+1]) {
            res++;
        }
        for (const auto& y : adj[x]) {
            dfs2(y,dist+1,dfs2);
        }
    };
    dfs(0,0,dfs);
    dfs2(0,0,dfs2);
    cout << res << '\n';
    for (const auto& [dist,cnt] : map) if (cnt > 1) res++;
    cout << res + n << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
