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
    int z=0,o=0;
    int l=0,r=0;
    while (r < n) {
        if (s[l]=='1') {
            o++;
            l++;
            r++;
        }
        else {
            z++;
            while (r+1 < n && s[r+1]=='0') {
                r++;
            }
            l = r+1;
            r = l;
        }
    }
    cout << (o>z ? "Yes" : "No") << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
