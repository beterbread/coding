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
    
    vector<vector<int>> res(n,vector<int>(n));
    int cur = n*n-1;
    int left = 0, right = n;
    int top = 0, bottom = n;
    while (left < right && top < bottom) {
        //get every element in top row
        for (int i = left; i < right; i++) {
            res[top][i] = cur;
            cur--;
        }
        top++;
        //get every element in right column
        for (int i = top; i < bottom; i++) {
            res[i][right - 1] = cur;
            cur--;
        }
        right--;
        if (!(left < right && top < bottom)) {
            break;
        }
        //get every element in bottom row;
        for (int i = right - 1; i > left - 1; i--) {
            res[bottom - 1][i] = cur;
            cur--;
        }
        bottom--;
        //get every element in left column
        for (int i = bottom - 1; i > top - 1; i--) {
            res[i][left] = cur;
            cur--;
        }
        left++;
    }
    
    each(x, res) {
        each(y, x) cout << y << " ";
        cout << "\n";
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
