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
    ll l,r; cin >> l >> r;
    auto f = [](ll n) -> ll {
        ll res = LLONG_MAX;
        ll sum = 0;
        for (int i = 0; i < 64; ++i) {
            sum += (1LL << i);
            if (sum >= n) {
                res = min(res,sum-n);
                break;
            }
            ll div = ceil(ld(n)/ld(sum));
            ll tot = (div*(sum-1))+1;
            cout << sum << ' ' << div << ' ' << tot << '\n';
            if (tot >= n) {
                res = min(res,div+(div-1)+(tot-n));
            }
        }
        return res;
    };
    ll res = 0;
    ll MOD = 998244353;
    for (ll n = l; n <= r; ++n) {
        res = (res + f(n)) % MOD;
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
