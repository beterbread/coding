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

int main() 
{ 
	fast_io

	int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> m;
        FOR(i, n) {
            int num;
            cin >> num;
            m[num]++;
        }
        // Just go through 1 to 100 (inclusive) and
        // check how many elements have at least that frequency
        int res = 0;
        rep(i, 1, 101) {
            int count = 0;
            each(x, m) {
                if (x.ss >= i) count++;
            }
            res = max(res, count * i);
        }
        cout << res << "\n";
    }
	
	return 0; 
} 
