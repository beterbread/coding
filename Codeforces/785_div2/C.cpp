#include <bits/stdc++.h>
using namespace std;

bool palindrome(int i) {
    string s = to_string(i);
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n = 40000;
    vector<int> a;
    for (int i = 1; i <= n; ++i) {
        if (palindrome(i)) a.push_back(i);
    }
    int m = a.size();
    vector<vector<int>> dp(m,vector<int>(n+1,0));
    const int MOD = 1e9+7;
    for (int i = 0; i < m; ++i) dp[i][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int joe = 0;
            if (j-a[i] >= 0) joe += dp[i][j-a[i]]; // pick
            if (i-1 >= 0) joe += dp[i-1][j]; // skip
            dp[i][j] = (dp[i][j] + joe) % MOD;
        }
    }
    int t; cin >> t;
    while (t--) {
        int q; cin >> q;
        cout << dp[m-1][q] << '\n';
    }
}