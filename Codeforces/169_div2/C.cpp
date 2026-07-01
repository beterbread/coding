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
    int n,q; cin >> n >> q;
    vector<ll> a(n);
    FOR(i,n) cin >> a[i];
    vector<ll> sweep(n,0);
    while (q--) {
        int l,r; cin >> l >> r; 
        l--; r--; // zero indexing
        sweep[l]++;
        if (r+1 < n) sweep[r+1]--;
    }
    priority_queue<ll> pq;
    ll joe = 0;
    FOR(i,n) {
        joe += sweep[i];
        // cout << joe << '\n';
        pq.push(joe);
    }
    ll res = 0;
    sort(all(a));
    FORD(i,n) {
        if (pq.empty()) break;
        res += a[i]*pq.top();
        pq.pop();
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
