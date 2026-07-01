#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,x; cin >> n >> x;
    vector<int> c(n);
    for (int& i : c) cin >> i;
    const int MOD = 1e9+7;
    int dp[n][x+1];
    memset(dp,0,sizeof(dp));
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            int res = 0;
            if (j-c[i] >= 0) res += dp[i][j-c[i]]; // pick
            if (i-1 >= 0) res += dp[i-1][j]; // skip
            dp[i][j] = (dp[i][j] + res) % MOD;
        }
    }
    cout << dp[n-1][x] << '\n';
}