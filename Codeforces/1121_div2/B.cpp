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
    vector<ll> a(n+1);
    FOR(i,n) cin >> a[i+1];
    vector<pair<ll,ll>> mx1(n+1,{LLONG_MIN,-1}); // max score, any
    mx1[0] = {0,0};
    vector<pair<ll,ll>> mx2(n+1,{-1,LLONG_MAX}); // score, max neg
    mx1[0] = {0,0};
    for (int i = 1; i <= n; ++i) {
        ll pick = mx1[i-1] + (i * (a[i] - mx1[i-1].ss));
        
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
