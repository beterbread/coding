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
    FOR(i,n-1) {
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<bool> color(n);
    vector<int> visited(n,false);
    auto dfs = [&](int a, bool col, auto&& dfs) -> void {
        if (visited[a]) return;
        visited[a] = true;
        color[a] = col;
        for (auto& b : adj[a]) {
            dfs(b,!col,dfs);
        }
    };
    dfs(0,true,dfs);
    ll red = 0, blue = 0;
    FOR(i,n) {
        red += color[i];
        blue += !color[i];
    }
    ll res = 0;
    FOR(i,n) {
        if (color[i]) res += blue-ll(adj[i].size());
        else res += red-ll(adj[i].size());
    }
    cout << res/2 << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
