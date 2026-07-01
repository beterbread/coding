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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(k);
    FOR(i, n) cin >> a[i];
    FOR(i, k) cin >> b[i];

    ll res = 0;
    priority_queue<int> pq_a(all(a));
    priority_queue<int,vector<int>,greater<int>> pq_b(all(b));
    while (!pq_b.empty() && !pq_a.empty()) {
        int x = pq_b.top(); pq_b.pop();
        if (x > pq_a.size()) continue;
        ll sum = 0, curr = -1;
        while (x > 0) {
            curr = pq_a.top(); pq_a.pop();
            sum += curr;
            x--;
        }
        res += (sum - curr);
    }
    while (!pq_a.empty()) {
        res += pq_a.top(); pq_a.pop();
    }

    cout << res << "\n";
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
