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
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    if (n&1) {
        cout << "-1\n";
        return;
    }
    vector<pair<int,int>> res;
    int sum = 0;
    for (int i = 0; i < n; i+=2) {
        if (a[i]+a[i+1]==0) {
            res.pb({i,i});
            res.pb({i+1,i+1});
        }
        else {
            res.pb({i,i+1});
        }
    }
    cout << res.size() << '\n';
    each(x,res) cout << x.ff+1 << ' ' << x.ss+1 << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
