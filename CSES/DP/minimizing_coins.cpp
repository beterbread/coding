#include <bits/stdc++.h> 
using namespace std; 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,x; cin >> n >> x;
    vector<int> c(n);
    for (int& i : c) cin >> i;
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i-c[j] >= 0 && dp[i-c[j]] != INT_MAX) {
                dp[i] = min(dp[i],dp[i-c[j]]+1);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
    return 0;
}