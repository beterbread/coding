#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
	vector<int> dp(n+1,INT_MAX); 
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (char c : to_string(i)) {
			dp[i] = min(dp[i],1+dp[i-(c-'0')]);
		}
	}
	cout << dp[n] << '\n';
}