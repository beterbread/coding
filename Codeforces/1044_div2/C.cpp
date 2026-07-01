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
    int n; cin >> n;
    
    string loc = "";
    FOR(i, n) loc += " " + to_string(i + 1);
    
    // Using n queries, find where the longest path starts
    map<int,vector<int>> m;
    FOR(i, n) {
        cout << "? " << (i + 1) << " " << n << loc << "\n";
        cout.flush();
        int ans; cin >> ans;
        m[ans].pb(i + 1);
    }
    
    int length = prev(m.end())->ff, curr = prev(m.end())->ss[0];
    vector<int> res;
    res.pb(curr);
    while (length > 1) {
        int next = -1;
        each(x, m[length - 1]) { // Find next node in the path
            cout << "? " << curr << " " << 2 << " " << curr << " " << x << "\n";
            cout.flush();
            int ans; cin >> ans;
            if (ans == 2) {
                next = x;
                break;
            }
        }
        res.pb(next);
        curr = next;
        length--;
    }
    
    cout << "! " << prev(m.end())->ff;
    each(x, res) cout << " " << to_string(x);
    cout << "\n";
    cout.flush();
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
