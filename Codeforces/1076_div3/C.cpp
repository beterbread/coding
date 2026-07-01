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
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    // apply optimal ops and precompute prefix
    FORD(i, n) {
        a[i] = max(a[i], b[i]);
        if (i + 1 < n) a[i] = max(a[i], a[i + 1]);
    }
    vector<int> pre(n);
    FOR(i, n) {
        pre[i] = a[i];
        if (i - 1 >= 0) pre[i] += pre[i - 1];
    }

    FOR(i, q) {
        int l, r; cin >> l >> r;
        l--; r--; // zero indexing
        ll res = pre[r] - (l == 0 ? 0 : pre[l - 1]);
        cout << res << " ";
    }
    cout << "\n";
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
