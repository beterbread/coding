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
#define FOR(i, n) for (ll i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   

void solve() {
    ll n,m; cin >> n >> m;
    vector<ll> joe(30);
    FOR(i,30) joe[i] = (1LL << i);
    unordered_set<ll> set;
    ll res = 0;
    while (1) {
        n %= m;
        if (n == 0) break;
        if (set.find(n) != set.end()) {
            res = -1;
            break;
        }
        set.insert(n);
        FOR(i,30) {
            if (joe[i] * n >= m) {
                res += i*n;
                n *= joe[i];
                break;
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
