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
    ll n,m,k; cin >> n >> m >> k;
    int w; cin >> w;
    vector<ll> a(w);
    FOR(i,w) cin >> a[i];
    sort(rall(a));
    priority_queue<ll> pq;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            ll l = max(0LL,i-k+1), r = min(n-1,i+k-1);
            ll joe = (r-l+1)-k+1;
            ll t = max(0LL,j-k+1), b = min(m-1,j+k-1);
            ll mama = (b-t+1)-k+1;
            pq.push(joe*mama);
        }
    }
    ll res = 0;
    FOR(i,w) {
        res += pq.top() * a[i];
        pq.pop();
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
