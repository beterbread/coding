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
    int n,m,q; cin >> n >> m >> q;
    vector<int> a(n),b(m);
    FOR(i,n) cin >> a[i];
    FOR(i,m) cin >> b[i];
    vector<int> joe(n+1,-1);
    int order = 1;
    FOR(i,n) {
        if (joe[a[i]] == -1) {
            joe[a[i]] = order++;
        }
    }
    vector<int> mama(n+1,-1);
    order = 1;
    FOR(i,m) {
        if (mama[b[i]] == -1) {
            mama[b[i]] = order++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (mama[i] != -1 && joe[i] != mama[i]) {
            cout << "TIDAK\n";
            return;
        }
    }
    cout << "YA\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
