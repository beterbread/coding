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
    ll x,y,z,k; cin >> x >> y >> z >> k;
    auto joe = [&](ll x2, ll y2, ll z2) -> ll {
        if (x2 > x || y2 > y || z2 > z) return 0;
        ll d1 = abs(x2-x)+1;
        ll d2 = abs(y2-y)+1;
        ll d3 = abs(z2-z)+1;
        ll res = d1*d2*d3;
        return res;
    };
    ll res = 0;
    for (ll i = 1; i <= x; ++i) {
        for (ll j = 1; j <= y; ++j) {
            if (i*j <= k && k%(i*j) == 0) {
                res = max(res,joe(i,j,k/(i*j)));
            }
        }
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
