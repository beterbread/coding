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
    vector<int> res(n+1,1);
    int prev = -1; 
    for (int r = 2; r <= n; ++r) {
        cout << "? 1 " << r << endl;
        int f; cin >> f;
        if (prev == -1) {
            if (f > 0) {
                prev = f;
                for (int i = r-1; i >= r-f; --i) {
                    res[i] = 0;
                }
            }
        }
        else {
            if (f > prev) {
                res[r] = 1;
            }
            else {
                res[r] = 0;
            }
            prev = f;
        }
    }
    if (prev == -1) {
        cout << "! IMPOSSIBLE" << endl; 
    }
    else {
        cout << "! ";
        for (int i = 1; i <= n; ++i) {
            cout << res[i];
        }
        cout << endl;
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
