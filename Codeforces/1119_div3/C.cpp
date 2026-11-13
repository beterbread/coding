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
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    int l = -1, r = -1;
    FOR(i,n) {
        if (a[i] != 0) {
            l = i;
            break;
        }
    }
    FORD(i,n) {
        if (a[i] != 0) {
            r = i;
            break;
        }
    }
    if (l != -1) a[l] = 1;
    if (r != -1) a[r] = 1;
    FOR(i,n) {
        if (i != l && i != r && a[i] == -1) {
            a[i] = 0;
        }
        cout << a[i] << ' ';
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
