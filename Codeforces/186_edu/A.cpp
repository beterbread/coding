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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int res1 = 0;
    FOR(i, n) {
        if (i + 3 == n) break;
        string tmp = s.substr(i, 4);
        if (tmp == "2025") res1++;
    }

    int res2 = INF_INT;
    FOR(i, n) {
        if (i + 3 == n) break;
        string tmp = s.substr(i, 4);
        int pos = 0;
        if (tmp[0] != '2') pos++;
        if (tmp[1] != '0') pos++;
        if (tmp[2] != '2') pos++;
        if (tmp[3] != '6') pos++;
        res2 = min(res2, pos);
    }

    cout << (res1 < res2 ? res1 : res2) << '\n';
}

int main() 
{ 
	fast_io

	int t;
    cin >> t;
    while (t--) {
        solve();
    }
	
	return 0; 
} 
