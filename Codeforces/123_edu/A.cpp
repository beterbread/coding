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
    string s; cin >> s;
    int r=0,g=0,b=0;
    each(c,s) {
        if (c=='r') r++;
        else if (c=='g') g++;
        else if (c=='b') b++;
        else if (c=='R') r--;
        else if (c=='G') g--;
        else if (c=='B') b--;
        if (r<0 || g<0 || b<0) {
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
