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
    vector<int> odd,even;
    each(x,a) {
        if (x&1) odd.pb(x);
        else even.pb(x);
    }
    sort(all(odd));
    sort(all(even));
    int idx = 0, idx2 = 0;
    FOR(i,n) {
        if (a[i]&1) {
            a[i] = odd[idx];
            idx++;
        }
        else {
            a[i] = even[idx2];
            idx2++;
        }
    }
    bool res = true;
    FOR(i,n-1) {
        if (a[i] > a[i+1]) {
            res = false;
            break;
        }
    }
    cout << (res ? "YES" : "NO") << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
