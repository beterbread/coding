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
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    int x = 0;
    for (int i = 1; i < n-1; ++i) x += (a[i] == 0);
    int joe = a[0] + a[n-1];
    if (joe == 2) {
        cout << (x < 2 ? -1 : 2) << '\n';
    }
    else if (joe == 1) {
        cout << (x < 1 ? -1 : 1) << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
