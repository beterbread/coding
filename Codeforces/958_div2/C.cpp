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
    ll n; cin >> n;
    vector<ll> res;
    res.pb(n);
    for (int i = 0; i <= 64; i++) {
        if (!(n&(1LL<<i))) continue;
        ll x = n;
        x ^= (1LL<<i);  
        if (x==0 || x>=res.back()) break;
        if (x!=n) res.pb(x);
    }
    cout << res.size() << '\n';
    FORD(i,res.size()) cout << res[i] << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
