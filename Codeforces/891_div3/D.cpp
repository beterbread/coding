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
    vector<int> a(n),b(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];
    // au - bu >= av - bv
    // sort ai - bi, neighbors of i are all nodes before it
    vector<pair<int,int>> c(n); // ai - bi, i
    FOR(i,n) c[i] = {a[i]-b[i],i};
    sort(all(c));
    vector<int> res;
    FOR(i,n) {
        if (c[i].ff == c[n-1].ff) {
            res.pb(c[i].ss+1);
        }
    }
    cout << res.size() << '\n';
    each(x,res) cout << x << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
