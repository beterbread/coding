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

int const N = 2*1e5;
ll fact[N+1];
// https://codeforces.com/blog/entry/78873
ll powmod(ll a, ll b, ll p){
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}
ll inv(ll a, ll p){
    return powmod(a, p-2, p);
}
ll nCk(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}

const int MOD = 1e9+7;
void solve() {
    int n,k; cin >> n >> k;
    vector<ll> a(n);
    FOR(i,n) cin >> a[i];
    int z=0, o=0;
    each(x,a) {
        z += x==0;
        o += x==1;
    }
    ll res = 0;
    for (int zeros = 0; zeros <= (k-1)/2 && zeros <= z; zeros++) {
        int ones = k-zeros;
        if (ones >= 1 && ones <= o) {
            res = (res + (nCk(z,zeros,MOD) * nCk(o,ones,MOD))) % MOD;
        }
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = (fact[i-1] * (ll)i) % MOD;
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
