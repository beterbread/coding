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
    ll mod = 998244353;
    vector<ll> dp(n);
    dp[0] = 1; 
    for (int i = 1; i < n; ++i) {
        ll joe = 0;
        for (int j = 0; j < i; ++j) {
            if (gcd(a[i],a[j]) != 1) {
                joe = (joe + dp[j]) % mod;
            }
        }
        dp[i] = joe;
    }
    cout << dp[n-1] << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
