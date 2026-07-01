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
    vector<int> par(n-1);
    FOR(i,n-1) {
        cin >> par[i];
        par[i]--;
    }
    string s; cin >> s;
    vector<vector<int>> adj(n);
    FOR(i,n-1) {
        adj[par[i]].push_back(i+1);
        // cout << par[i] << ' ' << i+1 << '\n';
    }
    int res = 0;
    auto rec = [&](int x, auto&& rec) -> pair<int,int> { 
        pair<int,int> p = {s[x]=='B',s[x]=='W'};
        if (adj[x].empty()) {
            return p;
        }
        for (auto& y : adj[x]) {
            pair<int,int> joe = rec(y,rec);
            p.ff += joe.ff;
            p.ss += joe.ss;
        }
        if (p.ff == p.ss) res++;
        return p;
    };
    rec(0,rec);
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
