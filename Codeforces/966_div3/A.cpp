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
    int a; cin >> a;
    string s = to_string(a);
    if (s.length() > 2 && s[0] == '1' && s[1] == '0' && (s[2]-'0' >= 2 || (s[2]-'0' >= 1 && s.length() > 3))) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
