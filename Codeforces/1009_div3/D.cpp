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
    ll n,m; cin >> n >> m;
    vector<ll> x(n),r(n);
    FOR(i,n) cin >> x[i];
    FOR(i,n) cin >> r[i];
    map<ll,ll> map;
    FOR(i,n) {
        ll center = x[i];
        map[center] = max(map[center],r[i]);
        for (ll d = 1; d <= r[i]; d++) {
            ll left = center-d, right = center+d;
            ll joe = floor(sqrt(r[i]*r[i]-d*d));
            map[left] = max(map[left],joe);
            map[right] = max(map[right],joe);
        }
    }
    ll res = 0;
    each(joe,map) {
        res += (joe.ss*2);
        res++;
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
