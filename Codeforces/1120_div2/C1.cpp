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
    vector<ll> a(n);
    FOR(i,n) cin >> a[i];
    int joe = count(all(a),0);
    if (joe == n) {
        cout << 0 << '\n';
        cout << '\n';
        return;
    }
    set<ll> bad;
    FOR(i,n) {
        ll mult = i+1;
        bad.insert(a[i]*mult);
    }
    vector<ll> res;
    for (ll i = 0; i < n; ++i) {
        if (bad.find(i) == bad.end()) {
            res.pb(i);
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
