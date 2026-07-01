#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<string> grid(n);
    for (string& s : grid) cin >> s;
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = grid[0][0] != '*';
    const int MOD = 1e9+7;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') continue;
            dp[i][j] = (dp[i][j] + (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0)) % MOD;
        }
    }
    cout << dp[n-1][n-1] << '\n';
}