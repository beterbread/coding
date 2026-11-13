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
    vector<string> a(n);
    FOR(i,n) cin >> a[i];
    int left = INT_MAX, right = INT_MIN;
    int top = INT_MAX, bot = INT_MIN;
    FOR(i,n) {
        FOR(j,m) {
            if (a[i][j] == '#') {
                left = min(left,j);
                right = max(right,j);
                top = min(top,i);
                bot = max(bot,i);
            }
        }
    }
    // cout << left << ' ' << right << ' ' << top << ' ' << bot << '\n';
    int x = (left + right) / 2;
    int y = (top + bot) / 2;
    cout << y+1 << ' ' << x+1 << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
