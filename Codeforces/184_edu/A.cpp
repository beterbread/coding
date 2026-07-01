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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)       
#define repd(i, a, b) for (int i = (a); i >= (b); --i)    
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

int main() 
{ 
	fast_io

	int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n >> a;
        vector<int> v(n);
        FOR(i, n) cin >> v[i];
        sort(all(v));
        int pos1 = a - 1, pos2 = a + 1;
        int res1 = 0, res2 = 0;
        each(x, v) {
            if (abs(x - pos1) < abs(x - a)) res1++;
            if (abs(x - pos2) < abs(x - a)) res2++;
        }
        if (res1 > res2) {
            cout << pos1 << "\n";
        }
        else {
            cout << pos2 << "\n";
        }
    }
	
	return 0; 
} 
