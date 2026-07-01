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
    ll x; cin >> x;
    ll y = 0;
    if (__builtin_popcountl(x) > 1) {
        for (int b = 0; b <= 31; b++) {
            if (x&(1<<b)) {
                y |= (1<<b);
                break;
            }
        }
    }
    else {
        bool joe = false, mama = false;
        for (int b = 0; b <= 31; b++) {
            if (!joe && x&(1<<b)) {
                joe = true;
                y |= (1<<b);
            }
            else if (!mama && !(x&(1<<b))) {
                mama = true;
                y |= (1<<b);
            }
            if (joe && mama) break;
        }
    }
    cout << y << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
