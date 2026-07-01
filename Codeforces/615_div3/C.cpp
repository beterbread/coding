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
    for (int i = 2; i <= sqrt(n); i++) {
        if (n%i == 0) {
            for (int j = 2; j <= sqrt(n/i); j++) {
                if ((n/i)%j == 0 && (n/i)/j >= 2 && i!=j && i!=(n/i)/j && j!=(n/i)/j) {
                    cout << "YES\n";
                    cout << i << ' ' << j << ' ' << (n/i)/j << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
