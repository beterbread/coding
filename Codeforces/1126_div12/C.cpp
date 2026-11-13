#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   

void solve() {
    int n; cin >> n;

}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    vector<int> joe = {3,3,1,2,0};
    for (int l = 0; l < joe.size(); ++l) {
        for (int r = 0; r < joe.size(); ++r) {
            if (l <= r) {
                int xo = joe[l];
                for (int i = l+1; i <= r; ++i) {
                    xo ^= joe[i];
                }
                if (xo == 0) {
                    cout << l << ' ' << r << '\n';
                }
            }
        }
    }
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
