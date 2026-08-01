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
    int n,m; cin >> n >> m;
    priority_queue<ll> a;
    priority_queue<ll,vector<ll>,greater<ll>> b;
    FOR(i,n) {
        ll x; cin >> x;
        a.push(x);
    }
    FOR(i,m) {
        ll x; cin >> x;
        b.push(x);
    }
    ll res = 0;
    FOR(i,n) {
        res += abs(a.top() - b.top());
        a.pop();
        b.pop();
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
