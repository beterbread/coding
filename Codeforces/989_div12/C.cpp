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
    vector<string> grid(n);
    FOR(i,n) cin >> grid[i];
    vector<vector<bool>> good(n,vector<bool>(m,false));
    FOR(i,n) {
        FOR(j,m) {
            if (grid[i][j] != '?') continue;
            if (i > 0 && (grid[i-1][j] == 'D' || good[i-1][j])) {
                grid[i][j] = 'U';
                good[i][j] = true;
            }
            else if (j > 0 && (grid[i][j-1] == 'R' || good[i][j-1])) {
                grid[i][j] = 'L';
                good[i][j] = true;
            }
            else if (i+1 < n && (grid[i+1][j] == 'U' || good[i+1][j])) {
                grid[i][j] = 'D';
                good[i][j] = true;
            }
            else if (j+1 < m && (grid[i][j+1] == 'L' || good[i][j+1])) {
                grid[i][j] = 'R';
                good[i][j] = true;
            }
        }
    }
    FOR(i,n) {
        FOR(j,m) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
