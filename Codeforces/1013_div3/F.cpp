#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   

// https://leetcode.com/problems/count-routes-to-climb-a-rectangular-grid/solutions/7462817/javacpython-dp-sliding-window-by-lee215-moj3/
int numberOfRoutes(vector<string>& grid, int d) {
    int n = grid.size(), m = grid[0].size();
    long long mod = 998244353;

    auto f = [&](const vector<long long>& dp, int dist, const string& r) {
        vector<long long> dp2(m);
        long long window = 0;
        for (int k = 0; k <= min(m - 1, dist); ++k)
            window += dp[k];
        dp2[0] = window;
        for (int j = 1; j < m; ++j) {
            window = dp2[j - 1];
            if (j - dist - 1 >= 0) window -= dp[j - dist - 1];
            if (j + dist < m) window += dp[j + dist];
            dp2[j] = window;
        }
        for (int j = 0; j < m; ++j) {
            dp2[j] = (r[j] == '#') ? 0 : dp2[j] % mod;
        }
        return dp2;
    };

    vector<long long> dp;
    for (int i = n - 1; i >= 0; --i) {
        const string& r = grid[i];
        if (dp.empty()) {
            dp = f(vector<long long>(m, 1), 0, r);
        } else {
            int d2 = sqrt(d * d - 1);
            dp = f(dp, d2, r);
        }
        dp = f(dp, d, r);
    }
    long long res = 0;
    for (long long v : dp)
        res = (res + v) % mod;
    return res;
}

void solve() {
    int n,m,d; cin >> n >> m >> d;
    vector<string> grid(n);
    FOR(i,n) cin >> grid[i];
    cout << numberOfRoutes(grid,d) << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
