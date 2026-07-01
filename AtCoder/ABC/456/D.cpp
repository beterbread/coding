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
    string s; cin >> s;
    int n = s.length();
    vector<vector<ll>> dp(n,vector<ll>(4));
    dp[0][s[0]-'a'] = 1;
    dp[0][3] = 1;
    for (int i = 1; i < n; ++i) {
        int idx = s[i]-'a';
        for (int j = 0; j < 4; ++j) {
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j == idx) continue;
            dp[i][idx] = (dp[i][idx] + dp[i-1][j]) % MOD;
        }
        // cout << dp[i][idx] << '\n';
    }

    // debug
    // for (int j = 0; j < 4; ++j) {
    //     if (j==0) cout << "A: ";
    //     else if (j==1) cout << "B: ";
    //     else if (j==2) cout << "C: ";
    //     else cout << "#: ";
    //     for (int i = 0; i < n; ++i) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    ll res = (dp[n-1][0] + dp[n-1][1] + dp[n-1][2]) % MOD;
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
