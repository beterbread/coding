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
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        if (a == b) {
            cout << "0\n";
            continue;
        }
        ll res = 0;
        if (a > b) {
            a = a ^ 1;
            res += y;
        }
        if (a > b) {
            cout << "-1\n";
            continue;
        }
        while (a < b) {
            ll next = a ^ 1;
            if (next > b) {
                a++;
                res++;
                continue;
            }
            if (y > (next - a) * x) { 
                a++;
                res += x;
            }
            else {
                a = next;
                res += y;
            }
        }
        cout << res << "\n";
    }
	
	return 0; 
} 
