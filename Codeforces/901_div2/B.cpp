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
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n),b(m);
    FOR(i,n) cin >> a[i];
    FOR(i,m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    if (k&1) {
        if (a[0] < b[m-1]) swap(a[0],b[m-1]);
    }
    if (k >= 2) {
        sort(all(a));
        sort(all(b));
        if (!(k&1) && a[n-1] > b[0]) swap(a[n-1],b[0]);
    }
    cout << accumulate(all(a),0LL) << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
