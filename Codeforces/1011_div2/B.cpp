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
    vector<int> idx;
    vector<int> a(n);
    FOR(i, n) {
        cin >> a[i];
        if (a[i] == 0) idx.pb(i + 1); // 1 to n 
    }

    int cnt = idx.size();
    if (cnt == 0) { // op entire array
        cout << "1\n";
        cout << "1 " << n << "\n";
    }
    else if (cnt == 1) { 
        // op the 0 with either the left or right element
        // then op entire array
        cout << "2\n";
        int pos = idx[0];
        if (pos == 1) cout << "1 2\n"; 
        else cout << (pos - 1) << " "<< pos << "\n"; 
        cout << "1 " << (n - 1) << "\n";
    }
    else {
        // pos1 to pos2 range contains ALL the 0s
        int pos1 = idx[0], pos2 = idx[idx.size() - 1]; 
        
        if (pos1 == 1 && pos2 == n) {
            // we can op each half of the range
            // each half both contain 0, so they both will become NOT 0 after the op
            // then we can op the remaining array, which becomes size 2
            int half = floor((double)n/2);
            cout << "3\n";
            cout << pos1 << " " << half << "\n";
            cout << "2 " << (n - half + 1) << "\n";
            cout << "1 2\n";
        }
        else {
            // we can op the entire range
            // then op the remaining array
            cout << "2\n";
            cout << pos1 << " " << pos2 << "\n";
            cout << "1 " << n - (pos2 - pos1) << "\n";
        }
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
