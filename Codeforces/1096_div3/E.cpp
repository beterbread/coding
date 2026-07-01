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
    ll base = 0;
    for (int i = n-2; i >= 0; i--) {
        base += max(0,a[i]-a[i+1]);
        a[i] -= max(0,a[i]-a[i+1]);
    }
    // cout << base << '\n';
    // each(x,a) cout << x << ' ';
    // cout << '\n';
    ll add = 0;
    ll l=0, r=0;
    while (r<n) {
        while (r+1<n && a[l]==a[r+1]) {
            r++;
        }
        add = max(add,r-l);
        l=r+1;
        r=l;
    }
    ll res = base+add;
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
