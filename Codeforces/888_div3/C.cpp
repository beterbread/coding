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
    vector<int> c(n);
    FOR(i,n) cin >> c[i];
    if (c[0] == c[n-1]) {
        cout << (count(all(c),c[0]) >= k ? "YES" : "NO") << '\n';
        return;
    }
    int mn = INT_MAX, mx = INT_MIN;
    int cnt = 0;
    FOR(i,n) {
        cnt += c[i] == c[0];
        if (cnt == k) {
            mn = i;
            break;
        }
    }
    cnt = 0;
    FORD(i,n) {
        cnt += c[i] == c[n-1];
        if (cnt == k) {
            mx = i;
            break;
        }
    }
    cout << (mn < mx ? "YES" : "NO") << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
