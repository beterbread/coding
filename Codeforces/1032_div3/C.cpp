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
    vector<vector<int>> mat(n, vector<int>(m));

    int mx = -1;
    int num;
    FOR(i, n) {
        FOR(j, m) {
            cin >> num;
            mat[i][j] = num;
            mx = max(mx, mat[i][j]);
        }
    }

    int r = -1, r_mx = -1;
    FOR(i, n) {
        int curr = 0;
        FOR(j, m) {
            if (mat[i][j] == mx) curr++;
        }
        if (curr > r_mx) {
            r = i;
            r_mx = curr;
        }
    }

    int c = -1, c_mx = -1;
    FOR(j, m) {
        int curr = 0;
        FOR(i, n) {
            if (mat[i][j] == mx) curr++;
        }
        if (curr > c_mx) {
            c = j;
            c_mx = curr;
        }
    }

    if (r_mx > c_mx) { // greedily choose this row
        FOR(j, m) mat[r][j]--; // decrement row
        int cnt = 0; // how many columns have mx
        FOR(j, m) {
            bool have = false;
            FOR(i, n) {
                if (mat[i][j] == mx) {
                    have = true;
                    break;
                }
            }
            if (have) cnt++;
            if (cnt == 2) break;
        }
        cout << (cnt <= 1 ? mx - 1 : mx) << "\n";
    }
    else { // greedily choose this column
        FOR(i, n) mat[i][c]--; // decrement column
        int cnt = 0; // how many rows have mx
        FOR(i, n) {
            bool have = false;
            FOR(j, m) {
                if (mat[i][j] == mx) {
                    have = true;
                    break;
                }
            }
            if (have) cnt++;
            if (cnt == 2) break;
        }
        cout << (cnt <= 1 ? mx - 1 : mx) << "\n";
    }
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
