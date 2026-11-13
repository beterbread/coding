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
    int n,q; cin >> n >> q;
    string s,t; cin >> s >> t;
    vector<int> pre(n);
    FOR(i,n) {
        pre[i] = s[i] == t[i];
        if (i > 0) pre[i] += pre[i-1];
    }
    while (q--) {
        int l,r; cin >> l >> r;
        l--;
        r--;
        int z = ceil(double(r-l+1)/2);
        int joe = pre[r] - (l == 0 ? 0 : pre[l-1]);
        if (joe >= z) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
