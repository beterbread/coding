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
    vector<vector<int>> a(n,vector<int>(m));
    FOR(i,n) FOR(j,m) cin >> a[i][j];
    while (1) {
        bool found = false;
        FOR(i,n) {
            FOR(j,m) {
                if ((i>0 && a[i][j] <= a[i-1][j]) || (j>0 && a[i][j] <= a[i][j-1]) || (i+1<n && a[i][j] <= a[i+1][j]) || (j+1<m && a[i][j] <= a[i][j+1])) continue;
                int joe = INT_MIN;
                if (i>0) joe = max(joe,a[i-1][j]);
                if (j>0) joe = max(joe,a[i][j-1]);
                if (i+1<n) joe = max(joe,a[i+1][j]);
                if (j+1<m) joe = max(joe,a[i][j+1]);
                a[i][j] = joe;
                found = true;
                break;
            }
            if (found) break;
        }
        if (!found) break;
    }
    FOR(i,n) {
        FOR(j,m) {
            cout << a[i][j] << ' ';
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
