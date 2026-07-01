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
    int n,m; cin >>n>>m;
    vector<vector<int>> adj(n);
    FOR(i,m) {
        int x,y; cin >>x>>y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    vector<bool> color(n);
    vector<bool> v1(n,false),v2(n,false),v3(n,false);
    auto dfs = [&](int x, bool red, auto&& dfs)->void{ // color graph
        v1[x]=true;
        color[x]=red;
        each(y,adj[x]) {
            if (!v1[y]) {
                dfs(y,!red,dfs);
            }
        }
    };
    int red=0,blue=0;
    auto dfs2 = [&](int x, auto&& dfs2)->void{ // get number of red and blue nodes
        if (color[x]) red++;
        else blue++;
        v2[x]=true;
        each(y,adj[x]) {
            if (!v2[y]) {
                dfs2(y,dfs2);
            }
        }
    };
    auto dfs3 = [&](int x, auto&& dfs3)->bool{ // check if bipartite
        bool res = true;
        v3[x]=true;
        each(y,adj[x]) {
            if (color[x]==color[y]) return false;
            if (!v3[y]) {
                res &= dfs3(y,dfs3);
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
        dfs2(i,dfs2);
        if (dfs3(i,dfs3)) res+=max(red,blue);
        red=0,blue=0;
    }
    cout << res << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
