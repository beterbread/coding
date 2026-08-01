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
    vector<string> grid(n);
    FOR(i,n) cin >> grid[i];
    int res = 0;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    FOR(i,n) {
        FOR(j,n) {
            int x = i, y = j;
            if (!visited[x][y]) {
                vector<int> joe;
                int mx = -1;
                while (!visited[x][y]) {
                    visited[x][y] = true;
                    mx = max(mx, grid[x][y] - 'a');
                    joe.pb(grid[x][y] - 'a');
                    int tmp_x = x;
                    x = y;
                    y = n-tmp_x-1;
                }
                each(mama,joe) {
                    res += mx - mama;
                }
            }
        }
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
