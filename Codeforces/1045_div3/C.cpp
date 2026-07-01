#include <bits/stdc++.h> 
using namespace std; 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int INF_INT = 1e9;
const ld EPS = 1e-9;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#define popcount(x) __builtin_popcount(x)
#define parity(x) __builtin_parity(x)
#define clzll(x) __builtin_clzll(x)
#define ctzll(x) __builtin_ctzll(x)
#define popcountll(x) __builtin_popcountll(x)
#define parityll(x) __builtin_parityll(x)

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    FOR(i, n) cin >> a[i];
    
    ll res = 0;
    for (int i = 1; i < n; i += 2) {
        // make left == a[i]
        if (a[i - 1] > a[i]) {
            res += (a[i - 1] - a[i]);
            a[i - 1] = a[i];
        }
        
        // ensure left + right is not greater than a[i]
        if (i + 1 < n) {
            ll sum = a[i - 1] + a[i + 1];
            if (sum > a[i]) {
                res += (sum - a[i]);
                a[i + 1] -= (sum - a[i]);
            }
        }
    }
    
    cout << res << "\n";
}

int main() 
{ 
	fast_io

	int t;
    cin >> t;
    while (t--) {
        solve();
    }
	
	return 0; 
} 
