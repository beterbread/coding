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
    if (n < 5) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i += 2) {
        if (i == 5) continue;
        cout << i << ' ';
    }
    cout << 5 << ' ' << 4 << ' ';
    for (int i = 2; i <= n; i += 2) {
        if (i == 4) continue;
        cout << i << ' ';
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
