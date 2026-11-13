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
    string a; cin >> a;
    int res = 0;
    FOR(i,n) {
        if (i == n-1 || a[i] != a[i+1]) {
            res++;
        }
    }
    int mx = 0;
    for (int i = 1; i < n-1; ++i) {
        if (a[i] != a[i-1] && a[i] != a[i+1]) {
            mx = max(mx,1);
            if (a[i-1] == a[i+1]) {
                mx = 2;
            }
        }
        if (mx == 2) break;
    }
    cout << res-mx << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
