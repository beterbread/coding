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
    int x1,x2,x3; cin >> x1 >> x2 >> x3;
    int n = x1+x2+x3;
    int dp[n][3][3];
    // place 1 first
    dp[0][0][0] = 1;
    dp[0][1][0] = 0;
    dp[0][2][0] = 0;
    // place 2 first
    dp[0][1][1] = 1;
    dp[0][0][1] = 0;
    dp[0][2][1] = 0;
    // place 3 first
    dp[0][2][2] = 1;
    dp[0][0][2] = 0;
    dp[0][1][2] = 0;
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < 3; k++) {
            int one = x1 - dp[i-1][0][k];
            int two = x2 - dp[i-1][1][k];
            int three = x3 - dp[i-1][2][k];
            if (k == 0) { // can add one or two
                
            }
            else if (k == 1) { // can add one, two, and three

            }
            else { // can add two or three

            }
        }
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
