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
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) a[i] %= 2;
    reverse(all(a));
    vector<int> diff(n);
    diff[0] = a[0];
    for (int i = 1; i < n; ++i) {
        diff[i] = a[i] - a[i-1];
    }
    auto update = [&](int l, int r, int x) {
        diff[l] += x;
        if (r+1 < n) {
            diff[r+1] -= x;
        }
    };
    int moves = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += diff[i];
        if (cur&1) {
            if (i+1 < n) update(i+1, min(n-1,i+k), 1);
            moves++;
        }
    }
    cout << (moves&1 ? "Alice" : "Bob") << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
