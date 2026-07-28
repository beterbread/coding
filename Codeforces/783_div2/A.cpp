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
    int og_n = n, og_m = m;
    n--;
    m--;
    int res = n + m;
    int mn = min(n,m);
    n -= mn+1;
    m -= mn+1;
    if (n > 0) {
        if (og_m > 1) {
            res += n;
            res += n&1;
        }
        else {
            res = -1;
        }
    }
    if (m > 0) {
        if (og_n > 1) {
            res += m;
            res += m&1;
        }
        else {
            res = -1;
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
