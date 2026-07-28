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
    vector<int> a(n),b(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];
    int joe = 0, mama = 0;
    int x = 0, y = 0; // one mismatch, zero mismatch
    FOR(i,n) {
        joe += a[i] == 0 && a[i] == b[i];
        mama += a[i] == 1 && a[i] == b[i];
        if (a[i] != b[i]) {
            x += a[i] == 1;
            y += a[i] == 0;
        }
    }
    if (x == 0 && y == 0) {
        cout << 0 << '\n';
        return;
    }
    if (x == 0) {
        if (joe > 0 && mama > 0) {
            cout << 2 << '\n';
        }
        else {
            cout << -1 << '\n';
        }
        return;
    }
    if (x%2 == 0) {
        cout << 2 << '\n';
    }
    else {
        cout << 1 << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
