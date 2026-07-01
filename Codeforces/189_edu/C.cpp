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
    int n; cin >> n;
    string a,b; cin >> a >> b;
    vector<int> dp(n+1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + (a[i-1] != b[i-1]);
        if (i > 1) dp[i] = min(dp[i], dp[i-2] + (a[i-2] != a[i-1]) + (b[i-2] != b[i-1]));
    }
    cout << dp[n] << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
