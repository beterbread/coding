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
    unordered_map<int,unordered_set<int>> map;
    while (m--) {
        int x,y; cin >> x >> y;
        if (x>y) swap(x,y);
        map[x].insert(y);
    }
    int res = 0;
    int l = 1, r = 1;
    while (r <= n) {
        while (r+1 <= n && (map.find(l)==map.end() || map[l].find(r+1)==map[l].end())) {
            r++;
        }
        // cout << l << ' ' << r << '\n';
        while (l <= r) {
            cout << l << ' ' << r << '\n';
            if (map.find(l)==map.end() || map[l].find(r)==map[l].end()) res++;
            l++;
        }
        r = l;
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
