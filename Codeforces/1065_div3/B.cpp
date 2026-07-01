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
    int n;
    cin >> n;
    vector<int> A(n);
    FOR(i, n) cin >> A[i];
    // All elements NON NEGATIVE (except -1 initially)
    if (A[0] == -1 && A[n - 1] == -1) {
        A[0] = A[n - 1] = 0;
    } 
    else if (A[0] == -1) {
        A[0] = A[n - 1];
    } 
    else if (A[n - 1] == -1) {
        A[n - 1] = A[0];
    }
    vector<int> diff(n - 1);
    FOR(i, n) {
        if (A[i] == -1) A[i] = 0;
        if (i + 1 < n) diff[i] = A[i + 1] - A[i];
    }
    cout << abs(A[n - 1] - A[0]) << "\n";
    each(i, A) cout << i << " ";
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
