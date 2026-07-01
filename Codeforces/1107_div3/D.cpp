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
    vector<ll> a(n),b(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];
    FORD(i,n) {
        if (a[i] > b[i] && i > 0) {
            a[i-1] += (a[i] - b[i]);
            a[i] = b[i];
        }
    }
    FOR(i,n) {
        if (a[i] < b[i]) a[i] = b[i];
    }
    cout << (a==b ? "YES" : "NO") << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
