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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T>
using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

void solve() {
    int n; cin >> n;
    vector<int> a(n),b(n);
    FOR(i,n) cin >> a[i] >> b[i];
    // for a valid pair x,y: 
    // ax < ay && bx > by
    ll res = 0;
    vector<pair<int,int>> c(n);
    FOR(i,n) c[i] = {a[i],i};
    sort(all(c));
    ordered_set<pair<int,int>> set;
    FOR(i,n) set.insert({b[i],i});
    FOR(i,n) {
        int joe = b[c[i].ss];
        set.erase({joe,c[i].ss});
        res += set.order_of_key({joe,-1});
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
