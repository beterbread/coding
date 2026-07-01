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

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    vector<ll> B(n);
    FOR(i, n) cin >> A[i];
    FOR(i, n) cin >> B[i];
    
    ll res = -INF;
    if (k % 2 == 0) {
        ll curr = 0;
        FOR(i, n) {
            curr += A[i];
            res = curr > res ? curr : res;
            if (curr < 0) curr = 0;
        }
    }
    else {
        vector<ll> pre(n); 
        ll curr = 0;
        FOR(i, n) {
            curr += A[i];
            pre[i] = curr;
            res = curr > res ? curr : res;
            if (curr < 0) {
                curr = 0;
            }
        }

        vector<ll> suf(n);
        curr = 0;
        FORD(i, n) {
            curr += A[i];
            suf[i] = curr;
            res = curr > res ? curr : res;
            if (curr < 0) {
                curr = 0;
            }
        }

        FOR(i, n) {
            ll pos = (pre[i] + suf[i] - A[i] + B[i]);
            res = pos > res ? pos : res;
        }
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
