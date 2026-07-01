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
    int n = s.length();
    int res = 0, four = 0;
    int one = 0, three = 0;
    int i = 0;
    while (i<n) {
        // pos1
        if (s[i]=='1') one++;
        if (s[i]=='3') three++;
        int two = 0;
        while (i<n && s[i]=='2') {
            two++;
            i++;
        }
        if (one+three<two) {
            one = 0;
            three = 0;
        }
        // four
        if (s[i]=='4') four++;
        i++;
    }
    cout << res+four << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
