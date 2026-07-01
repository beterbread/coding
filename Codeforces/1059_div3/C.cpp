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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)       
#define repd(i, a, b) for (int i = (a); i >= (b); --i)    
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
    int a, b;
    cin >> a >> b;
    // a has MORE leading zeros
    // cannot transform a into b 
    // example:
    // a = 00010
    // b = 10000
    // We need x = 10000 to set the MSB of a to 1
    // This is not allowed as x has to be less than a
    if (clz(a) > clz(b)) {
        cout << "-1\n";
        return;
    }

    // No operations needed
    if (a == b) {
        cout << "0\n";
        return;
    }

    // There must be at least one operation
    vector<int> ops;
    // 2^30 > 10^9
    FOR(i, 31) {
        int bit_a = a & 1;
        int bit_b = b & 1;
        if (bit_a != bit_b) {
            ops.pb(pow(2, i));
        }
        a >>= 1;
        b >>= 1;
    }
    cout << ops.size() << "\n";
    each(i, ops) cout << i << " ";
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
