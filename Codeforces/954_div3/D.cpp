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
    if (n == 2) {
        if (s[0] == '0') cout << s.substr(1,1) << '\n';
        else cout << s << '\n';
        return;
    }
    int res = INT_MAX;
    FOR(i,n-1) {
        int joe = (s[i] - '0') * 10;
        if (s[i+1] == '0') {
            joe /= 10;
        }
        else {
            joe += (s[i+1] - '0');
        }
        if (joe == 0) {
            res = 0; 
            break;
        }
        FOR(j,n) {
            if (j == i || j == i+1) continue;
            if (s[j] == '0') {
                joe = 0;
                break;
            }
            if (s[j] != '1') {
                joe += (s[j] - '0');
            }
        }
        res = min(res,joe);
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
