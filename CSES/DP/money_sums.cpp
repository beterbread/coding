#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int W = accumulate(a.begin(),a.end(),0);
    bool dp[n+1][W+1];
    memset(dp,false,sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (dp[i-1][j]) dp[i][j] = true; // skip
            if (j-a[i-1] >= 0 && dp[i-1][j-a[i-1]]) dp[i][j] = true; // pick
        }
    }
    vector<int> res;
    for (int j = 1; j <= W; j++) {
        if (dp[n][j]) res.push_back(j);
    }
    cout << res.size() << '\n';
    for (auto& i : res) cout << i << ' ';
    cout << '\n';
}