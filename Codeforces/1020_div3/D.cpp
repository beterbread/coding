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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    FOR(i, n) cin >> a[i];
    FOR(i, m) cin >> b[i];
    
    vector<int> pre(m), suf(m);
    int curr = 0;
    FOR(i, m) {
        while (curr < n && a[curr] < b[i]) curr++;
        pre[i] = curr;
        curr++;
    }
    curr = n - 1;
    FORD(i, m) {
        while (curr >= 0 && a[curr] < b[i]) curr--;
        suf[i] = curr;
        curr--;
    }
    
    // each(x, pre) cout << x << " ";
    // cout << "\n";
    // each(x, suf) cout << x << " ";
    // cout << "\n";
    
    if (pre.back() < n) {
        cout << "0\n";
        return;
    }
    if (m == 1) {
        cout << b[0] << "\n";
        return;
    }
    
    int res = INT_MAX;
    FOR(i, m) {
        if (i == 0) {
            if (suf[i + 1] > -1) res = min(res, b[i]);
        }   
        else if (i == m - 1) {
            if (pre[i - 1] < n) res = min(res, b[i]);
        }
        else if (pre[i - 1] < suf[i + 1]) {
            res = min(res, b[i]);
        }
    }
    cout << (res == INT_MAX ? -1 : res) << "\n";
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