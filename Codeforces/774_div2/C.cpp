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

vector<ll> fac;
void solve() {
    ll n; cin >> n;
    int res = __builtin_popcountll(n);
    vector<bool> take(fac.size(),false);
    auto rec = [&](int i, auto&& rec) -> void {
        if (i == fac.size() || fac[i] > n) {
            int joe = 0;
            ll sum = 0;
            for (int j = 0; j < i; j++) {
                if (take[j]) {
                    sum += fac[j];
                    joe++;
                }
            }
            if (sum<=n) res = min(res,__builtin_popcountll(n-sum)+joe);
            return;
        }
        rec(i+1,rec);
        take[i] = true;
        rec(i+1,rec);
        take[i] = false;
    };
    rec(0,rec);
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    ll n = 1e12;
    ll cur = 1;
    ll f = 1;
    while (cur <= n) {
        fac.pb(cur);
        cur *= f; 
        f++;
    }
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
