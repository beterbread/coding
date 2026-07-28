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
    vector<vector<int>> a(n,vector<int>(2));
    FOR(i,n) FOR(j,2) cin >> a[i][j];
    sort(all(a),[](const vector<int> x, const vector<int> y){
        int joe = (x[0] <= y[0]) + (x[0] <= y[1]) + (x[1] <= y[0]) + (x[1] <= y[1]);
        int mama = (y[0] <= x[0]) + (y[0] <= x[1]) + (y[1] <= x[0]) + (y[1] <= x[1]);
        return joe >= mama;
    });
    FOR(i,n) cout << a[i][0] << ' ' << a[i][1] << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
