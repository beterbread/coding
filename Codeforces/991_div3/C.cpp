#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int INF_INT = 1e9;
const ld EPS = 1e-9;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#define popcount(x) __builtin_popcount(x)
#define parity(x) __builtin_parity(x)
#define clzll(x) __builtin_clzll(x)
#define ctzll(x) __builtin_ctzll(x)
#define popcountll(x) __builtin_popcountll(x)
#define parityll(x) __builtin_parityll(x)

void solve() {
    string s; cin >> s;
    
    // if sum of digits % 9 == 0, then divisible by 9
    
    ll sum = 0;
    int two = 0, three = 0;
    each(c, s) {
        int num = (c - '0');
        sum += num;
        if (num == 2) two++;
        if (num == 3) three++;
    }

    // check possible combinations
    for (int i = 0; i <= min(two, 10); i++) {
        for (int j = 0; j <= min(three, 10); j++) {
            ll diff = (i * 2) + (j * 6);
            if ((sum + diff) % 9 == 0) {
                cout << "YES\n";
                return;
            }
        }
    }
    
    cout << "NO\n";
}

int main() 
{ 
	fast_io
    
    int t; cin >> t;
    while (t--) {
        solve();
    }
	
	return 0; 
} 
