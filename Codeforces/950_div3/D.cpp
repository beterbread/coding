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
    if (n == 3) {
        cout << "YES\n";
        return;
    }
    vector<int> b(n-1);
    FOR(i,n-1) b[i] = gcd(a[i],a[i+1]);

    // debug
    // FOR(i,n-1) cout << b[i] << ' ';
    // cout << '\n';

    vector<bool> pre(n-1), suf(n-1);
    pre[0] = true;
    suf[n-2] = true;
    bool ok = true;
    for (int i = 1; i < n-1; ++i) {
        if (b[i] < b[i-1]) {
            ok = false;
        }
        pre[i] = ok;
    }
    ok = true;
    for (int i = n-3; i >= 0; --i) {
        if (b[i] > b[i+1]) {
            ok = false;
        }
        suf[i] = ok;
    }

    // debug
    // FOR(i,n-1) cout << pre[i] << ' ';
    // cout << '\n';
    // FOR(i,n-1) cout << suf[i] << ' ';
    // cout << '\n';

    if (suf[1] || pre[n-3]) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < n-1; ++i) {
        int joe = gcd(a[i-1],a[i+1]);
        bool ok = i-2 >= 0 ? b[i-2] <= joe && pre[i-2] : 1;
        bool ok2 = i+1 < n-1 ? b[i+1] >= joe && suf[i+1] : 1;
        if (ok && ok2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
