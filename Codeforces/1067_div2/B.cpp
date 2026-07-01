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
    vector<int> A(2*n);
    FOR(i, 2*n) cin >> A[i];

    unordered_map<int, int> freq;
    each(x, A) freq[x]++;

    int res = 0;
    int odd = 0, even = 0; 
    each(x, freq) {
        int f = x.ss;
        if (f % 2 == 0) {
            // If split is even, split with minimal difference is f/2 - 1 and f/2 + 1 with a difference of 2
            if ((f / 2) % 2 == 0) even++; 
            else res += 2; // If split is odd, then we can safely add f/2 to p and q
            // We can just add 2 to the res
        }
        else {
            odd++;; // Use as fillers, odd numbers have a contribution to 1
            // For example, 3 you cannot split such that BOTH p and q have a distinct element with an odd frequency
        }
    }
    res += odd; 
    // If we have an even number of frequencies such that f/2 is even, we can add 2 * even because they balance each other out
    // If we have an odd number of frequencies, then unless we have any odd frequencies to fill the remaining p and q, 
    // then ONE of the numbers will not contribute because we need to add f/2 elements to p and q which is an even frequency
    res += (2 * even);
    if (even % 2 == 1 && odd == 0) res -= 2;

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
