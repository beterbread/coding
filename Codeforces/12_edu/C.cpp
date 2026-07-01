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
    for (int i = 1; i < n-1; i++) {
        if (s[i-1] == s[i] && s[i+1] == s[i]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i]) {
                    s[i] = c;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n-1; i++) {
        if (s[i+1] == s[i]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i] && (i==0 || s[i-1] != c)) {
                    s[i] = c;
                    break;
                }
            }
        } 
    }
    cout << s << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
