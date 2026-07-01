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
    int n, Ax, Ay, Bx, By; cin >> n >> Ax >> Ay >> Bx >> By;
    vector<pair<int,int>> a;
    FOR(i, n) cin >> a[i].ff;
    FOR(i, n) cin >> a[i].ss;

    vector<pair<int,int>> range(Bx + 1, {INF_INT, -INF_INT}); // min y and max y for each x
    FOR(i, n) {
        range[a[i].ff].ff = min(range[a[i].ff].ff, a[i].ss);
        range[a[i].ff].ss = max(range[a[i].ff].ff, a[i].ss);
    }

    // can only go right
    ll res = Bx - Ax;
    pair<int,int> prev_min = {-1, -1};
    pair<int,int> prev_max = {-1, -1};
    
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
