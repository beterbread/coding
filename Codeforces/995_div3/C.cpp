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
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(m);
    FOR(i,m) cin >> a[i];
    vector<int> q(k);
    FOR(i,k) cin >> q[i];
    if (k < n-1) {
        FOR(i,m) cout << '0';
        cout << '\n';
    }
    else if (k == n) {
        FOR(i,m) cout << '1';
        cout << '\n';
    }
    else {
        vector<bool> joe(n+1,false);
        FOR(i,k) {
            joe[q[i]] = true;
        }
        int mama = -1;
        for (int i = 1; i <= n; ++i) {
            if (!joe[i]) {
                mama = i;
                break;
            }
        }
        FOR(i,m) {
            cout << (a[i] == mama);
        }
        cout << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
