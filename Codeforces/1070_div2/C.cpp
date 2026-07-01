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
    vector<ll> o, e;
    FOR(i, n) {
        ll num; cin >> num;
        if (num % 2) o.pb(num);
        else e.pb(num);
    }

    ll mx = !o.empty() ? *max_element(all(o)) : -1; // use for all odd or later
    if (e.size() == 0) { // all odd
        FOR(i, n) cout << (i % 2 == 0 ? mx : 0) << " ";
        cout << "\n";
        return;
    }
    else if (o.size() == 0) { // all even
        FOR(i, n) cout << 0 << " ";
        cout << "\n";
        return;
    }
    
    sort(all(e));
    int sz = e.size();
    vector<ll> pre(sz);
    FOR(i, sz) {
        pre[i] = e[i];
        if (i > 0) pre[i] += pre[i - 1];
    }

    vector<ll> res(n);
    FOR(i, n) {
        // first number before evens always odd
        // can put up to i even numbers at the end
        int len = i + 1;
        int evens = min(i, sz);
        // optimal to add as many evens as possible UNLESS it makes the freq of odd numbers even
        int odds = len - evens;
        if (odds % 2 == 0) { // odd count is even
            // can we add one more odd and one less even?
            // we can certainly delete an even number
            // but check if odds + 1 is possible
            if (odds + 1 > o.size()) { // if not then the result is 0
                res[i] = 0;
                continue;
            }
            else {
                evens--;
                res[i] = mx + (pre[sz - 1] - (sz - evens - 1 < 0 ? 0 : pre[sz - evens - 1]));
            }
        }
        else { // odd count is odd so we can add
            res[i] = mx + (pre[sz - 1] - (sz - evens - 1 < 0 ? 0 : pre[sz - evens - 1]));
        }
    }

    each(x, res) cout << x << " ";
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
