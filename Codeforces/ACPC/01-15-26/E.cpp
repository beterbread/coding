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

ll cnt(vector<vector<int>>& dp, int i, int j) {
    ll count = 0;
    for (int x = i + 1; x < 11; x++) count += dp[x][j];
    for (int x = i - 1; x >= 0; x--) count += dp[x][j];
    for (int y = j + 1; y < 11; y++) count += dp[i][y];
    for (int y = j - 1; y >= 0; y--) count += dp[i][y];
    return count;
}

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    FOR(i, n) cin >> a[i];

    // a b c d e f g h i j k
    vector<vector<int>> dp(11, vector<int>(11, 0));
    FOR(i, n) dp[a[i][0] - 'a'][a[i][1] - 'a']++;
    
    ll res = 0;
    FOR(i, 11) {
        FOR(j, 11) {
            if (dp[i][j] > 0) {
                ll count = cnt(dp, i, j);
                res += (count * dp[i][j]);
            }
        }
    }

    cout << (res / 2) << "\n";
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
