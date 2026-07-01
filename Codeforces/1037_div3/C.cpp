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

vector<int> clean(vector<int>& a, int k) {
    vector<int> res;
    int n = a.size();
    FOR(i, n) {
        if (a[i] < a[k]) continue;
        if (i < n - 1 && a[i] == a[i + 1]) continue;
        res.pb(a[i]);
    }
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    k--; // zero indexing
    vector<int> a(n);
    FOR(i, n) cin >> a[i];

    // remove duplicates and any elements less than a[k] and sort
    vector<int> b = clean(a, k);
    sort(all(b));
    // each(x, b) cout << x << " ";
    // cout << endl;
    
    n = b.size();
    int water = 1;
    for (int i = 1; i < n; i++) {
        water += (b[i] - b[i - 1]);
        if (water - 1 > b[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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
