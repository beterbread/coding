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
    vector<vector<int>> adj(n);
    while (m--) {
        int a,b; cin >> a >> b;
        a--; b--; // zero indexing
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<bool> color(n);
    vector<bool> v1(n,false), v2(n,false);
    auto dfs = [&](int x, bool red, auto&& dfs)->void{ // color graph
        v1[x]=true;
        color[x]=red;
        each(y,adj[x]) {
            if (!v1[y]) {
                dfs(y,!red,dfs);
            }
        }
    };
    auto dfs2 = [&](int x, auto&& dfs2)->bool{ // check if bipartite
        bool res = true;
        v2[x]=true;
        each(y,adj[x]) {
            if (color[x]==color[y]) return false;
            if (!v2[y]) {
                res &= dfs2(y,dfs2);
            }
        }
        return res;
    };
    FOR(i,n) {
        if (!v1[i]) dfs(i,true,dfs);
    }
    int res = 0;
    FOR(i,n) {
        if (v2[i]) continue;
        if (!dfs2(i,dfs2)) {
            cout << "0\n";
            return;
        }
        res++;
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
