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
    int m; cin >> m;
    vector<int> d(m);
    FOR(i,m) cin >> d[i];
    multiset<int> joe(all(a));
    multiset<int> set(all(b));
    int overwrite = 0;
    FORD(i,m) {
        auto it = set.find(d[i]);
        if (it != set.end()) {
            overwrite++;
            set.erase(it);
        }
        else {
            if (overwrite == 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << (set.empty() ? "YES" : "NO") << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
