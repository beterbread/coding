#include <bits/stdc++.h> 
using namespace std; 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int INF_INT = 1e9;
const ld EPS = 1e-9;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)       
#define repd(i, a, b) for (int i = (a); i >= (b); --i)    
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   

bool valid(int x, int m){
    return x >= 1 && x <= m;
}

int main() 
{ 
	fast_io

    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    FOR(i, n) cin >> A[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // dp[i][k] = number of ways to build a prefix of size i
    // such that the last element of the prefix is k
    
    // base case dp[1][k] = 1 if (a[0] = 0 OR a[0] = k)
    for(int i = 1; i <= m; i++){
        if(A[0] == i || A[0] == 0)
            dp[1][i] = 1;
    }
    
    rep(i, 2, n + 1) {
        rep(k, 1, m + 1) {
            // finding dp[i][k] here
            if (A[i - 1] != 0 && A[i - 1] != k) {
                dp[i][k] = 0;
                continue;
            }
            
            rep(prev, k - 1, k + 2) { // k - 1, k, k + 1
                if (!valid(prev, m)) continue;
                // transition
                dp[i][k] = (dp[i][k] + dp[i - 1][prev]) % MOD;
            }
        }
    }
    
    int res = 0;
    rep(i, 1, m + 1) res = (res + dp[n][i]) % MOD;
    
    // final subproblem
    cout << res << endl;
	
	return 0; 
} 
