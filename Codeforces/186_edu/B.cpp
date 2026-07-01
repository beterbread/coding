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
    int a, b;
    cin >> a >> b;
    int a2 = a, b2 = b; 

    int res1 = 0;
    bool white = true;
    int i = 1;
    while ((white && a >= i) || (!white && b >= i)) {
        if (white) a -= i;
        else b -= i;
        res1++;
        white = !white; 
        i *= 2;
    }

    int res2 = 0;
    white = false;
    i = 1;
    while ((white && a2 >= i) || (!white && b2 >= i)) {
        if (white) a2 -= i;
        else b2 -= i;
        res2++;
        white = !white; 
        i *= 2;
    }

    cout << (res1 > res2 ? res1 : res2) << "\n";
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
