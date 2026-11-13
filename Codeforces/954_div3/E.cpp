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
    ll k; cin >> k;
    vector<ll> a(n);
    FOR(i,n) cin >> a[i];
    map<ll,vector<ll>> map;
    FOR(i,n) {
        map[a[i]%k].pb(a[i]);
    }
    ll res = 0;
    int odds = 0;
    for (auto& [nocare,v] : map) {
        sort(all(v));
        int sz = v.size();
        if (sz&1) {
            odds++;
            if (n&1 && odds != 1) {
                cout << -1 << '\n';
                return;
            }
            else if (!(n&1) && odds > 0) {
                cout << -1 << '\n';
                return;
            }
            vector<ll> pre(sz), suf(sz);
            for (int i = 1; i < sz; i+=2) {
                pre[i] = ((v[i]-v[i-1]) / k);
                if (i > 1) pre[i] += pre[i-2];
            }
            for (int i = 2; i < sz; i+=2) {
                pre[i] = pre[i-1];
            }
            for (int i = sz-2; i >= 0; i-=2) {
                suf[i] = ((v[i+1]-v[i]) / k);
                if (i+2 < sz) suf[i] += suf[i+2];
            }
            for (int i = sz-3; i >= 0; i-=2) {
                suf[i] = suf[i+1];
            }
            ll joe = LLONG_MAX;
            for (int i = 0; i < sz; ++i) {
                ll mama = 0;
                if (i > 0) mama += pre[i-1];
                if (i+1 < sz) mama += suf[i+1];
                if (i&1 && i+1 < sz && i-1 >= 0) {
                    mama += ((v[i+1]-v[i-1]) / k);
                }
                joe = min(joe,mama);
            }
            res += joe;
        }
        else {
            for (int i = 0; i < sz; i+=2) {
                res += ((v[i+1]-v[i]) / k);
            }
        }
    }
    if (n&1 && odds != 1) {
        cout << -1 << '\n';
    }
    else if (!(n&1) && odds > 0) {
        cout << -1 << '\n';
    }
    else {
        cout << res << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
