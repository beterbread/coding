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
    int n,k; cin >> n >> k;
    vector<pair<int,int>> a(n);
    FOR(i,n) {
        cin >> a[i].ff;
        a[i].ss = i;
    }
    sort(all(a));
    pair<int,int> res = {-1,-1};
    ll best = -1, res2 = -1;
    FOR(i,n-1) {
        ll pos = 0, pos2 = 0;
        FOR(b,k) {
            int b1 = a[i].ff&(1<<b), b2 = a[i+1].ff&(1<<b);
            if (b1 == b2) {
                if (b1 == 0) pos ^= (1<<b);
                pos2 ^= (1<<b);
            }
        }
        if (pos2 > best) {
            best = pos2;
            res = {a[i].ss,a[i+1].ss};
            res2 = pos;
        }
    }
    cout << res.ff+1 << ' ' << res.ss+1 << ' ' << res2 << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
