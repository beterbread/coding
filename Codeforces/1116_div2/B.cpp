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
const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> dp(n,vector<int>(2));
    dp[0][0] = s[0] != '1';
    dp[0][1] = s[0] != '0';
    dp[1][0] = (s[1] != '1') + (s[0] == '?');                                                  
    dp[1][1] = (s[1] != '0') + (s[0] == '?');
    for (int i = 2; i < n; ++i) {
        if (s[i] == '?') {
            // can make this 0 if previous is 10 or 11
            if (dp[i-2][1] && dp[i-1][0]) dp[i][0] = (dp[i][0] + dp[i-1][0]) % MOD;
            if (dp[i-2][1] && dp[i-1][1]) dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
            // can make this 1 if previous is 00 or 01
            if (dp[i-2][0] && dp[i-1][0]) dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
            if (dp[i-2][0] && dp[i-1][1]) dp[i][1] = (dp[i][1] + dp[i-1][1]) % MOD;
        }
        else if (s[i] == '0') {
            // can make this 0 if previous is 10 or 11
            if (dp[i-2][1] && dp[i-1][0]) dp[i][0] = (dp[i][0] + dp[i-1][0]) % MOD;
            if (dp[i-2][1] && dp[i-1][1]) dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
        }
        else if (s[i] == '1') {
            // can make this 1 if previous is 00 or 01
            if (dp[i-2][0] && dp[i-1][0]) dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
            if (dp[i-2][0] && dp[i-1][1]) dp[i][1] = (dp[i][1] + dp[i-1][1]) % MOD;
        }
        if (dp[i][0] == 0 && dp[i][1] == 0) return void(cout << 0 << '\n');
    }
    FOR(i,n) cout << dp[i][0] << ' ';
    cout << '\n';
    FOR(i,n) cout << dp[i][1] << ' ';
    cout << '\n';
    int res = (dp[n-1][0] + dp[n-1][1]) % MOD;
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
