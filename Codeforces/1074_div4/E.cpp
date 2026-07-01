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
    vector<int> a(n);
    FOR(i, n) cin >> a[i];
    vector<int> b(m);
    FOR(i, m) cin >> b[i];
    string s; cin >> s;

    sort(all(b));
    unordered_map<int,vector<int>> map;
    each(x, a) {
        int l = 0, r = m;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (b[mid] > x) r = mid;
            else l = mid + 1;
        }
        if (l - 1 >= 0) map[b[l - 1] - x].pb(x);
        if (l != m) map[b[l] - x].pb(x);
    }

    unordered_set<int> dead;
    int curr = 0;
    FOR(i, k) {
        curr += (s[i] == 'L' ? -1 : 1);
        each(x, map[curr]) dead.insert(x);
        map.erase(curr);
        cout << n - dead.size() << " ";
    }
    cout << "\n";
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
