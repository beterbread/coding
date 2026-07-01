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
    int x, y, z; cin >> x >> y >> z;

    // cout << pow(2, 30) << " " << 1e9 << "\n";
    vector<int> a(31, 0);
    vector<int> b(31, 0);
    vector<int> c(31, 0);
    
    // a & b = x
    FOR(i, 31) {
        int bit = (x >> i) & 1;
        if (bit) {
            a[i] = 1;
            b[i] = 1;
        }
    }

    // b & c = y
    FOR(i, 31) {
        int bit = (y >> i) & 1;
        if (bit) {
            b[i] = 1;
            c[i] = 1;
        }
    }

    // a & c == z
    FOR(i, 31) {
        int bit = (z >> i) & 1;
        if (bit) {
            a[i] = 1;
            c[i] = 1;
        }
    }

    // check conflicts

    // a & b = x
    FOR(i, 31) {
        int bit = (x >> i) & 1;
        if (!bit && (a[i] == 1 && b[i] == 1)) {
            cout << "NO\n";
            return;
        }
    }

    // b & c = y
    FOR(i, 31) {
        int bit = (y >> i) & 1;
        if (!bit && (b[i] == 1 && c[i] == 1)) {
            cout << "NO\n";
            return;
        }
    }

    // a & c == z
    FOR(i, 31) {
        int bit = (z >> i) & 1;
        if (!bit && (a[i] == 1 && c[i] == 1)) {
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
