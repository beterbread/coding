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
    int n,k; cin >> n >> k;
    vector<ll> a(n);
    FOR(i,n) cin >> a[i];
    sort(all(a));
    ll sum = 0;
    for (int i = n-k; i < n; ++i) {
        sum += a[i];
    }
    if (n-k-1 < 0 || a[n-k-1] * k < sum) {
        cout << "YES\n";
        for (int i = n-k; i < n; ++i) {
            cout << a[i] << ' ';
        }
        for (int i = n-k-1; i >= 0; --i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
