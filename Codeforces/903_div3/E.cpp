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
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    vector<int> dp(n+1);
    dp[n] = 0;
    dp[n-1] = 1;
    for (int i = n-2; i >= 0; --i) {
        int pick = 1 + dp[i+1];
        int choose = i + a[i] + 1 <= n ? dp[i + a[i] + 1] : INT_MAX;
        dp[i] = min(pick,choose);
    }
    cout << dp[0] << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
