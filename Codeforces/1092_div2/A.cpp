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
    vector<int> a(k+1);
    FOR(i,k) cin >> a[i+1];
    unordered_map<int,vector<int>> map;
    FOR(i,n) {
        int joe; cin >> joe;
        map[joe].pb(i+1);
    }
    vector<int> res;
    while (map[k+1].size() < n) {
        bool ok = false;
        for (int i=k+1; i>=2; i--) {
            if ((i==k+1 || map[i].size()<a[i]) && !map[i-1].empty()) {
                res.pb(map[i-1].back());
                map[i].pb(map[i-1].back());
                map[i-1].pop_back();
                ok=true;
                break;
            }
        }
        if (!ok) break;
        if (res.size() > 1000) {
            cout << "-1\n";
            return;
        }
    }
    cout << res.size() << '\n';
    each(x,res) cout << x << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
