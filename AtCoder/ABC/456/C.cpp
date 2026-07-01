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

const int MOD = 998244353;
void solve() {
    string s; cin >> s;
    int n = s.length();
    int l=0, r=0;
    ll res = 0;
    while (r<n) {
        while (r+1<n && s[r+1]!=s[r]) r++;
        // cout << l << ' ' << r << '\n';
        ll x = r-l+1;
        ll add = x*(x+1)/2;
        res = (res+add)%MOD;
        l=r+1;
        r=l;
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
