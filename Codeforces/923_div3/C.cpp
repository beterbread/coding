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
    vector<int> a(k + 1), b(k + 1);
    FOR(i, n) {
        int num; cin >> num;
        if (num >= 1 && num <= k) {
            a[num]++;
        }
    }
    FOR(i, m) {
        int num; cin >> num;
        if (num >= 1 && num <= k) {
            b[num]++;
        }
    }
    int x = 0, y = 0, z = 0; 
    for (int i = 1; i <= k; i++) {
        if (a[i] == 0 && b[i] == 0) {
            cout << "NO\n";
            return;
        }
        if (a[i] > 0 && b[i] > 0) z++;
        else if (a[i] > 0) x++;
        else y++;
    }
    if (x > k / 2 || y > k / 2) {
        cout << "NO\n";
        return; 
    }
    int diff = (k / 2) - x;
    if (y + (z - diff) == k / 2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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
