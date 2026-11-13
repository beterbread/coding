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
    ll mn = LLONG_MAX;
    ll sum = 0, cnt = 0;
    ll res = 0;
    FOR(i,n) {
        cnt++;
        if (a[i] < 0) {
            res += (sum + abs(a[i]));
            if (cnt&1) {
                res -= (2 * mn);
            }
            
            continue;
        }
        mn = min(mn,a[i]);
        sum += a[i];
    }
    cout << (res + sum) << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
