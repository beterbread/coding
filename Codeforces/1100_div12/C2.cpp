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
    vector<ll> a(n);
    FOR(i,n) cin >> a[i];
    vector<ll> pre(n),abs_pre(n);
    pre[0] = a[0];
    abs_pre[0] = abs(a[0]);
    for (int i = 1; i < n; i++) {
        pre[i] = a[i] + pre[i-1];
        abs_pre[i] = abs(a[i]) + abs_pre[i-1];
    }
    // for each i, sum = -a[i] + abs_pre[i-1] + pre[n-1] - pre[i]
    ll sum = accumulate(all(a),0LL);
    int idx = -1;
    FOR(i,n) {
        if (a[i]>0) {
            ll pos = -a[i] + (i>0 ? abs_pre[i-1] : 0) + pre[n-1] - pre[i];
            if (pos > sum) {
                sum = pos;
                idx = i;
            }
        }
    }
    vector<int> res;
    if (idx>0) {
        bool par = true;
        for (int i = idx-1; i >= 0; i--) {
            if (par && a[i]>0) {
                res.pb(i+1);
                par = false;
            }
            else if (!par && a[i]<0) {
                res.pb(i+1);
                par = true;
            }
        }
        res.pb(idx+1);
    }
    cout << res.size() << '\n';
    each(x,res) cout << x << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
