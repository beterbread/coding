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
    ll x,y; cin >> x >> y;
    vector<ll> a(n);
    FOR(i,n) cin >> a[i];
    vector<ll> b = a;
    sort(all(b));
    ll sum = accumulate(all(a),0LL);
    ll res = 0;
    FOR(i,n) {
        ll joe = sum - a[i];
        if (joe <= x) continue; 
        ll mn = joe <= y ? 0 : joe - y; 
        ll mx = joe - x;
        auto l_it = lower_bound(all(b),mn);
        auto r_it = upper_bound(all(b),mx);
        if (l_it == b.end()) continue;
        int l = n - distance(l_it,b.end());
        int r = n - distance(r_it,b.end()) - 1;
        ll add = (r-l+1);
        res += add;
        if (a[i] >= mn && a[i] <= mx) res--;
    }
    cout << (res/2) << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
