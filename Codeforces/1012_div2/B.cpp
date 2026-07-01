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

bool check(int x, int y, vector<string>& mat) {
    // elements x, y to 0, y should be all '1' OR
    // elements x, y to x, 0 should be all '1'
    bool res = false;
    int x2 = x;

    while (x >= 0) {
        if (mat[x][y] != '1') break;
        if (x == 0) res |= true;
        x--;
    }

    while (y >= 0) {
        if (mat[x2][y] != '1') break;
        if (y == 0) res |= true;
        y--;
    }

    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<string> mat(n);
    FOR(i, n) cin >> mat[i];

    // for each '1', check if it was possible to be pushed from left or right
    FOR(i, n) {
        FOR(j, m) {
            if (mat[i][j] == '1' && !check(i, j, mat)) {
                cout << "NO\n";
                return;
            }
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
