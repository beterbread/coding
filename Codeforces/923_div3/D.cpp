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

    vector<int> left(n);
    int curr = -1;
    FOR(i, n) {
        left[i] = curr;
        if (i < n - 1 && a[i] != a[i + 1]) {
            curr = i;
        }
    }
    // each(x, left) cout << x << " ";
    // cout << "\n";

    vector<int> right(n);
    curr = -1;
    FORD(i, n) {
        right[i] = curr;
        if (i > 0 && a[i] != a[i - 1]) {
            curr = i;
        }
    }
    // each(x, right) cout << x << " ";
    // cout << "\n";

    int q; cin >> q;
    while (q > 0) {
        int l, r; cin >> l >> r;
        l--;
        r--; // zero indexing
        
        pair<int,int> res = {-1, -1};
        if (left[r] != -1 && left[r] >= l) {
            res = {left[r] + 1, r + 1};
        }
        else if (right[l] != -1 && right[l] <= r) {
            res = {l + 1, right[l] + 1};
        }
        cout << res.ff << " " << res.ss << "\n";

        q--;
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
