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
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    vector<ll> dp(n+1);
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (i <= k) {
            dp[i] = 0;
            continue;
        }
        int joe = i;
        vector<int> f;
        for (int x = 2; x * x <= joe; x++) {
            while (joe % x == 0) {
                f.push_back(x);
                joe /= x;
            }
        }
        if (joe > 1) f.push_back(joe);
        ll mama = LLONG_MAX;
        each(x,f) {
            if (dp[i/x] == 0) {
                mama = 1;
                continue;
            }
            mama = min(mama,1+x*dp[i/x]);
        }
        dp[i] = mama;
    }
    ll res = 0;
    each(x,a) {
        res += dp[x];
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
