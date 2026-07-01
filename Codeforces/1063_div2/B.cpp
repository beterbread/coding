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
    int min_pos = -1, max_pos = -1;

    int n;
    cin >> n;
    vector<int> p(n);
    FOR(i, n) {
        cin >> p[i];
        if (p[i] == 1) min_pos = i + 1;
        if (p[i] == n) max_pos = i + 1;
    }
    string s;
    cin >> s;

    // Leftmost and rightmost element cannot be 1
    // Position of min element and max element can never be 1
    if (s[0] == '1' || s[n - 1] == '1' || s[min_pos - 1] == '1' || s[max_pos - 1] == '1') {
        cout << "-1\n";
        return;
    }    
    else {
        cout << "5\n";
        cout << "1 " << min_pos << "\n";
        cout << "1 " << max_pos << "\n";
        cout << min_pos << " " << n << "\n";
        cout << max_pos << " " << n << "\n";
        cout << min(min_pos, max_pos) << " " << max(min_pos, max_pos) << "\n";
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
