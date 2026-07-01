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
    int h,w; cin >> h >> w;
    vector<vector<int>> res(h,vector<int>(w,0));
    FOR(i,h) {
        FOR(j,w) {
            if (i>0) res[i][j]++;
            if (j>0) res[i][j]++;
            if (i+1<h) res[i][j]++;
            if (j+1<w) res[i][j]++;
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
