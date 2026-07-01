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
    vector<int> a(n),b(m);
    FOR(i,n) cin >> a[i];
    FOR(i,m) cin >> b[i];
    set<int> set(all(b));
    a[0]=min(a[0],min(*set.begin()-a[0],*prev(set.end())-a[0]));
    for (int i = 1; i<n; i++) {
        int want=a[i-1]+a[i];
        auto it = set.lower_bound(want);
        if (it!=set.end()) {
            if (a[i]>=a[i-1]) a[i]=min(a[i],*it-a[i]);
            else a[i]=*it-a[i];
        }
        if (a[i-1]>a[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
