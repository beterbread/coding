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
    int k; cin >> k;
    int want = k-2;
    set<int> set;
    int n = -1, m = -1;
    while (k--) {
        int x; cin >> x;
        if (n == -1 && want % x == 0 && set.find(want / x) != set.end()) {
            n = x;
            m = want / x;
        }
        set.insert(x);
    }
    cout << n << ' ' << m << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
