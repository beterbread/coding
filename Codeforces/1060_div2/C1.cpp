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

const int range = 1e5 * 2;
vector<vector<int>> sieve(range + 1);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    unordered_map<int, int> m;
    each(i, a) {
        each(j, sieve[i]) { // prime factors of i
            m[j]++;
            if (m[j] == 2) {
                cout << "0\n";
                return;
            }
        }
    }

    each(i, a) {
        each(j, sieve[i + 1]) { // prime factors of i + 1
            if (m[j] > 0) {
                cout << "1\n";
                return;
            }
        }
    }

    cout << "2\n";
}

int main() 
{ 
	fast_io

    for (int i = 2; i <= range; i++) {
        if (sieve[i].empty()) { // i is prime
            for (int j = i; j <= range; j += i) {
                sieve[j].push_back(i);
            }
        }
    }


	int t;
    cin >> t;
    while (t--) {
        solve();
    }
	
	return 0; 
} 
