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
    vector<int> h(n);
    FOR(i,n) cin >> h[i];
    FOR(i,n) {
        vector<int> w(n);
        w[i] = 0;
        int prev = i-1<0 ? n-1 : i-1;
        int next = i+1>=n ? 0 : i+1;
        w[prev] = h[prev];
        w[next] = h[next];
        while (next-- > i) {
            w[next] = min(h[next],h[next+1]);
        }
        each(x,w) cout << x << ' ';
        cout << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
