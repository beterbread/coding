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
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    map<int,int> map;
    each(x,a) map[x]++;
    while (map.size()) {
        auto pp = prev(map.end());
        int x = pp->ff, cnt = pp->ss;
        FOR(i,cnt) cout << x << ' ';
        map.erase(prev(map.end()));
        vector<int> CLEAN;
        for (auto& [y,cnt2] : map) {
            FOR(i,min(cnt,cnt2)) cout << y << ' ';
            cnt2 -= min(cnt,cnt2);
            if (cnt2 == 0) {
                CLEAN.pb(y);
            }
        }
        // clean
        each(y,CLEAN) map.erase(y);
    }
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
