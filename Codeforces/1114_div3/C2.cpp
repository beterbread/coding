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
    if (n <= 3) {
        string b_rev = b;
        reverse(all(b));
        cout << (a == b ? 0 : a == b_rev ? 1 : -1) << '\n';
        return;
    }
    vector<vector<int>> dp(n,vector<int>(2,INT_MAX));
    for (int i = n-1; i >= n-3; --i) {
        dp[i][0] = a[i] != 0;
        dp[i][1] = a[i] != 1;
    }
    for (int i = n-4; i >= 0; --i) {
        if (a[i] != b[i]) {
            if (a[i] == '0') {
                int joe = a[i+2] == '0' ? dp[i+2][0] : dp[i+2][1];
                dp[i][0] = joe + 1;
            }
            else {
                int joe = a[i+2] == '0' ? dp[i+2][0] : dp[i+2][1];
                dp[i][1] = joe + 1;
            }
        }
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
