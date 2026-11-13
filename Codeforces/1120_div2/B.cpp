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
    int n,k; cin >> n >> k;
    if (!(k >= n && k < 2*n)) {
        cout << -1 << '\n';
        return;
    }
    int diff = k-n;
    vector<vector<int>> res(n,vector<int>(n,-1));
    res[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (diff > 0) {
            res[i][0] = i+1;
        }
        else {
            res[i][i] = i+1;
        }
        diff--;
    }
    int cur = n+1;
    FOR(i,n) {
        FOR(j,n) {
            if (res[i][j] == -1) {
                res[i][j] = cur;
                cur++;
            }
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
