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
        
        int res = 1;
        int win = n;
        int lose = 0;
        while (win >= 2 || lose >= 2) {
            if (lose >= 2) {
                res += (lose / 2);
                lose -= (lose / 2);
            }
            if (win >= 2) {
                res += (win / 2);
                lose += (win / 2);
                win -= (win / 2);
            }
        }
        cout << res << "\n";
    }
	
	return 0; 
} 
