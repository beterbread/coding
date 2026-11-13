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

    map<int,vector<int>> map;
    FOR(i,n) {
        map[a[i]].pb(i);
    }
    vector<int> map2(26,INT_MAX);

    int m; cin >> m;
    while (m--) {
        string s; cin >> s;
        if (s.length() != n) {
            cout << "NO\n";
            continue;
        }
        bool res = true;
        for (auto &[num,v] : map) {
            int prev = -1;
            each(x,v) {
                if (prev == -1) {
                    prev = s[x]-'a';
                }
                else if (prev != s[x]-'a') {
                    res = false;
                    break;
                }
            }
            if (!res) break;
        }
        if (res) {
            FOR(i,n) {
                int j = s[i]-'a';
                if (map2[j] == INT_MAX) {
                    map2[j] = a[i];
                }
                else {
                    if (map2[j] != a[i]) {
                        res = false;
                        break;
                    }
                }
            }
            FOR(i,26) map2[i] = INT_MAX;
        }
        cout << (res ? "YES" : "NO") << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
