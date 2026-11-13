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
    int n,m,q; cin >> n >> m >> q;
    set<int> set;
    while (m--) {
        int x; cin >> x;
        set.insert(x);
    }
    while (q--) {
        int x; cin >> x;
        auto low = set.lower_bound(x);
        auto high = set.upper_bound(x);
        int res = -1;
        if (low == set.begin()) { // teacher to the right
            res = (x-1)+(*low-x);
        }
        if (low != set.begin() && high != set.end()) { // teacher to the left and the right
            res = ceil(double(*high - *prev(low) + 1) / 2.0) - 1;
        }
        if (high == set.end()) { // teacher to the left 
            res = (n-x)+(x-*prev(low));
        }
        cout << res << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
