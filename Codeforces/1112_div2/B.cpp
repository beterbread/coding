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
    int n,k; cin >> n >> k;
    int ones = 0, zeros = 0;
    if (k > 0) {
        ones += 2;
        k--;
    }
    if (k > 0) {
        zeros += 2;
        k--;
    }
    FOR(i,k) {
        if (zeros <= ones) {
            zeros++;
        }
        else {
            ones++;
        }
    }
    int joe = 0;
    if (ones > 0 && zeros == 0) {
        joe = 1;
        n--;
    }
    n -= (ones + zeros);
    if (n < 0) {
        cout << -1 << '\n';
        return;
    }
    if (joe) cout << 0;
    int tog = zeros ? 1 : 0;
    FOR(i,ones) cout << 1;
    FOR(i,zeros) cout << 0;
    FOR(i,n) {
        cout << (tog ? 1 : 0);
        tog = !tog;
    }
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
