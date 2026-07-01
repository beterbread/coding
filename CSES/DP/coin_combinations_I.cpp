#include <bits/stdc++.h> 
using namespace std; 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,x; cin >> n >> x;
    vector<int> c(n);
    for (int& i : c) cin >> i;
    vector<int> dp(x+1);
    dp[0] = 1;
    const int MOD = 1e9+7;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i-c[j] >= 0) {
                dp[i] = (dp[i] + dp[i-c[j]]) % MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}