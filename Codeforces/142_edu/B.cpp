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
    int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;
    
    if (a1 == 0) {
        cout << (a2 > 0 || a3 > 0 || a4 > 0 ? "1" : "0") << "\n";
        return;
    }
    
    int mn = min(a2, a3);
    int res = a1 + (2 * mn);
    a2 -= mn;
    a3 -= mn;
    int A = a1, B = a1; // moods
    if (a2 != 0) {
        mn = min(B + 1, a2);
        A += mn;
        B -= mn;
        res += mn;
    }
    if (a3 != 0) {
        mn = min(A + 1, a3);
        B += mn;
        A -= mn;
        res += mn;
    }
    if (A > -1 && B > -1 && a4 > 0) {
        mn = min(min(A, B) + 1, a4);
        res += mn;
    }
    
    cout << res << "\n";
}

int main() 
{ 
	fast_io
    
    int t; cin >> t;
    while (t--) {
        solve();
    }
	
	return 0; 
} 
