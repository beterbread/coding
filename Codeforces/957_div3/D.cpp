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
    int n, m, k; cin >> n >> m >> k;
    string a; cin >> a;
    
    int curr = -1; // want to get to n
    while (1) {
        if (curr + m >= n) {
            cout << "YES\n";
            return;
        }
        int land = -1, water = -1;
        for (int i = curr + 1; i <= curr + m; i++) {
            if (a[i] == 'L') land = i;
            if (a[i] == 'W') water = i;
        }
        if (land != -1) { // optimal to jump to farthest land
            curr = land;
        }
        else { // optimal to jump to farthest water and swim to next land
            curr = water;
            while (a[curr] != 'L') {
                if (k == 0 || a[curr] == 'C') {
                    cout << "NO\n";
                    return;
                }
                k--;
                curr++;
                if (curr == n) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
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
