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
const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    if (n == 1) { 
        cout << "0\n";
        return;
    }
    sort(a.begin(),a.end());
    vector<int> bits(30);
    FOR(b,30) {
        each(x,a) {
            if (x&(1<<b)) bits[b]++;
        }
    }

    // debug
    FOR(b,30) cout << bits[b] << ' ';
    cout << '\n';

    int res = 0;
    each(x,a) {
        int pos = 1;
        FOR(b,30) {
            int o=-1, z=-1;
            if (x&(1<<b)) {
                o = bits[b]-1;
                z = n-o;

            }
            else {
                o = bits[b];
                z = n-o;

            }
        }
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
