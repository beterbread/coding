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
    string s; cin >> s;
    unordered_set<char> v={'a','c'}, c={'b','c','d'};
    string res = "";
    int l = 0, r = 1;
    while (l < n) {
        res.pb(s[l]);
        res.pb(s[r]);
        if (r + 1 < n && c.count(s[r+1])) {
            if (r + 2 == n || c.count(s[r+2])) {
                res.pb(s[r+1]);
                r++;
            }
        }
        l = r+1;
        r = l+1;
        if (l < n) res.pb('.');
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
