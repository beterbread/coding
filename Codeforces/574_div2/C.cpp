#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n),b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    vector<vector<long long>> dp(n,vector<long long>(3));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    dp[0][2] = b[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        dp[i][1] = a[i] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = b[i] + max(dp[i-1][0],dp[i-1][1]);
    }
    cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << '\n';
}
