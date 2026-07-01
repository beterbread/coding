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
    vector<int> a(n);
    FOR(i, n) cin >> a[i];

    vector<int> b;
    vector<int> pre_o(n), pre_z(n);
    FOR(i, n) {
        if (i + 1 < n && a[i] == a[i + 1]) b.pb(i);

        if (a[i] == 1) pre_o[i]++;
        else pre_z[i]++;
        if (i > 0) {
            pre_o[i] += pre_o[i - 1];
            pre_z[i] += pre_z[i - 1];
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--; // zero indexing

        int ones = pre_o[r] - (l == 0 ? 0 : pre_o[l - 1]);
        int zeros = pre_z[r] - (l == 0 ? 0 : pre_z[l - 1]);

        if (ones % 3 != 0 || zeros % 3 != 0) {
            cout << "-1\n";
            continue;
        }
        
        bool check = false;
        auto low = lower_bound(all(b), l);
        if (low != b.end()) check = *low + 1 <= r;

        cout << (ones / 3) + (zeros / 3) + (!check ? 1 : 0) << "\n";
    }
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
