#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,x; cin >> n >> x;
    vector<int> price(n),pages(n);
    for (int& i : price) cin >> i;
    for (int& i : pages) cin >> i;
    int dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = max(dp[i][j],dp[i-1][j]); // skip
            if (j-price[i-1] >= 0) // pick
                dp[i][j] = max(dp[i][j],dp[i-1][j-price[i-1]]+pages[i-1]);
        }
    }
    int res = INT_MIN;
    for (int j = 1; j <= x; j++) res = max(res,dp[n][j]);
    cout << res << '\n';
}