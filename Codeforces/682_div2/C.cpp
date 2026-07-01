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
    vector<vector<int>> grid(n,vector<int>(m));
    FOR(i,n) FOR(j,m) cin >> grid[i][j];
    FOR(i,n) {
        FOR(j,m) {
            if (i%2==0) {
                if (j%2==0 && grid[i][j]%2==0) {
                    grid[i][j]++;
                }
                else if (j%2==1 && grid[i][j]%2==1) {
                    grid[i][j]++;
                }
            }
            else {
                if (j%2==0 && grid[i][j]%2==1) {
                    grid[i][j]++;
                }
                else if (j%2==1 && grid[i][j]%2==0) {
                    grid[i][j]++;
                }
            }
            cout << grid[i][j] << ' ';
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
