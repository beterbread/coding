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
    vector<int> joe;
    FOR(i,n) {
        if (s[i] == '1') {
            joe.pb(i+1);
        }
    }
    sort(all(joe));
    if (joe.size() == 1) {
        cout << 0 << '\n';
        return;
    }
    else if (joe.size() > 2) {
        cout << joe[joe.size()-1] - joe[0] << '\n';
        return;
    }
    else if (joe.size() == n) {
        cout << n-1 << '\n';
        return;
    }
    int res = joe[1] - joe[0];
    FOR(i,n) {
        if (s[i] == '0') {
            res = min(res,max(joe[1],i+1)-min(joe[1],i+1));
        }
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
