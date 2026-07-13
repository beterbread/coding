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
    int n,k; cin >> n >> k;
    vector<ll> c(n);
    FOR(i,n) cin >> c[i];
    FOR(i,k) {
        int free; cin >> free; 
        free--; // zero indexing
        c[free] = 0;
    }
    vector<int> indegree(n);
    vector<vector<int>> adj(n);
    vector<vector<int>> need(n);
    FOR(i,n) {
        int m; cin >> m;
        while (m--) {
            int par; cin >> par;
            par--; // zero indexing
            adj[par].pb(i);
            indegree[i]++;
            need[i].pb(par);
        }
    }
    queue<int> q;
    FOR(i,n) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        ll buy = c[x];
        ll make = need[x].empty() ? LLONG_MAX : 0;
        for (int par : need[x]) {
            make += c[par];
        }
        c[x] = min(buy,make);
        for (int y : adj[x]) {
            indegree[y]--;
            if (indegree[y] == 0) {
                q.push(y);
            }
        }
    }
    FOR(i,n) cout << c[i] << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
