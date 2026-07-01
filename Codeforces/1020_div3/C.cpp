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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    int mx = INT_MIN, mn = INT_MAX;
    
    // possible x
    unordered_set<int> s;
    FOR(i, n) {
        if (b[i] != -1) {
            s.insert(a[i] + b[i]);
        }
        // multiple possible x
        if (s.size() > 1) {
            cout << "0\n";
            return;
        }
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    // one possible x
    if (s.size() == 1) {
        int x = *s.begin();
        FOR(i, n) {
            if (b[i] == -1) {
                if (a[i] > x || x - a[i] > k) {
                    cout << "0\n";
                    return;
                }
            }
        }
        cout << "1\n";
        return;
    }

    // b is full of -1
    cout << k - (mx - mn) + 1 << "\n";
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
