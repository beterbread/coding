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
const int MOD = 998244353;

void solve() {
    ll n,m,r,c; cin >> n >> m >> r >> c;
    ll joe = (long long)(pow(2LL,max(n,m)+1)) % MOD;
    ll res = (long long)(pow(2LL,r*c)) % MOD;
    res = (res * joe) % MOD;
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
