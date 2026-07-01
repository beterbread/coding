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

vector<bool> sieve;
void solve() {
    int n; cin >> n;
    ll res = 0;
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) {
            res += floor(double(n)/double(i));
        }
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    sieve.resize(10000001,true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i] && (long long)i * i <= 10000000) {
            for (int j = i * i; j <= 10000000; j += i) {
                sieve[j] = false;
            }
        }
    }
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
