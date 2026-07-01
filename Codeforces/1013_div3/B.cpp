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
    ll x; cin >> x;
    vector<ll> a(n);
    FOR(i,n) cin >> a[i];
    int res = 0;
    priority_queue<ll> pq(all(a));
    while (!pq.empty() && pq.top() >= x) {
        pq.pop();
        res++;
    }
    int sz = 0;
    while (!pq.empty()) {
        ll joe = pq.top(); pq.pop();
        sz++;
        if (sz*joe >= x) {
            res++;
            sz = 0;
        }
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
