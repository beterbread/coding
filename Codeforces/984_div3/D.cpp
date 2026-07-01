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
    vector<string> mat(n);
    FOR(i, n) cin >> mat[i];
    
    int res = 0;
    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    int xx = 0, yy = 0;
    while (left < right && top < bottom) {
        string s = "";
        int x = xx, y = yy;
        while (y <= right) {
            s.pb(mat[x][y]);
            y++;
        }
        y--;
        x++;
        while (x <= bottom) {
            s.pb(mat[x][y]);
            x++;
        }
        x--;
        y--;
        while (y >= left) { 
            s.pb(mat[x][y]);
            y--;
        }
        y++;
        x--;
        while (x > top) {
            s.pb(mat[x][y]);
            x--;
        }
        left++; right--; top++; bottom--;
        xx++; yy++;
        
        // check 
        int sz = s.length();
        FOR(i, sz) {
            if (i + 3 < sz && s[i] == '1' && s[i + 1] == '5' && s[i + 2] == '4' && s[i + 3] == '3') res++;
            if (i == sz - 1 && s[i] == '1' && s[0] == '5' && s[1] == '4' && s[2] == '3') res++;
            if (i == sz - 2 && s[i] == '1' && s[i + 1] == '5' && s[0] == '4' && s[1] == '3') res++;
            if (i == sz - 3 && s[i] == '1' && s[i + 1] == '5' && s[i + 2] == '4' && s[0] == '3') res++;
        }
    }
    cout << res << "\n";
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