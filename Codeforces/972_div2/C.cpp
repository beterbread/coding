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

void solve() {
    int n,m; cin >> n >> m;
    vector<string> a(n+1);
    FOR(i,n) cin >> a[i+1];
    unordered_map<char,int> map;
    map['n'] = 0;
    map['a'] = 1;
    map['r'] = 2;
    map['e'] = 3;
    map['k'] = 4;
    vector<vector<int>> dp(n+1,vector<int>(5,INT_MIN)); 
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1];
        for (int j = 0; j <= 4; ++j) {
            if (dp[i-1][j] == INT_MIN) continue;
            int cost = 0;
            int it = j;
            each(c,a[i]) {
                if (map.find(c) != map.end()) {
                    if (map[c] == it) {
                        cost++;
                        it++;
                        if (it == 5) it = 0;
                    }
                    else {
                        cost--;
                    }
                }
            }
            dp[i][it] = max(dp[i][it],dp[i-1][j]+cost);
        }
    }
    int res = 0;
    for (int j = 0; j <= 4; ++j) {
        if (dp[n][j] == INT_MIN) continue;
        res = max(res,dp[n][j]-2*j);
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
