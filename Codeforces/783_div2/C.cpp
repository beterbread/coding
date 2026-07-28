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
    ll res = LLONG_MAX;
    FOR(i,n) {
        ll pos = 0;
        ll prev = 0;
        for (int j = i-1; j >= 0; --j) {
            ll mult = ceil(ld(prev)/ld(a[j]));
            if (prev % a[j] == 0) mult++;
            pos += mult;
            prev = a[j]*mult;
        }
        prev = 0;
        for (int j = i+1; j < n; ++j) {
            ll mult = ceil(ld(prev)/ld(a[j]));
            if (prev % a[j] == 0) mult++;
            pos += mult;
            prev = a[j]*mult;
        }
        res = min(res,pos);
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
