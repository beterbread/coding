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
    vector<int> a(n),og(n);
    FOR(i,n) {
        cin >> a[i];
        og[i] = a[i];
    }
    ll base = 0;
    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = n-2; i >= 0; i--) {
            ll joe = max(0,a[i]-a[i+1]);
            if (joe>0) ok = true;
            base += joe;
            a[i] -= joe;
            a[i+1] += joe;
        }
    } 
    // cout << base << '\n';
    // each(x,a) cout << x << ' ';
    // cout << '\n';
    // each(x,og) cout << x << ' '; 
    // cout << '\n';
    int add = 0;
    for (int i = 1; i < n; i++) {
        auto it = lower_bound(all(a),og[i]);
        if (it==a.end()) continue;
        int idx = distance(a.begin(),it);
        add = max(add,i-idx);
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
