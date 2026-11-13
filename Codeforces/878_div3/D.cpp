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
    sort(all(a));
    auto feasible = [&](int mx) -> bool {
        if (n <= 3) return true;
        int joe = a[0] + mx;
        int mama = a[n-1] - mx;
        int trythis = -1, trythat = -1;
        for (int i = 1; i < n-1; ++i) {
            if (abs(a[i]-joe) > mx && abs(a[i]-mama) > mx) {
                trythis = max(1,a[i]-mx), trythat = min(1000000000,a[i]+mx);
                break;
            }
        }
        if (trythis == -1 && trythat == -1) return true;
        for (int i = 1; i < n-1; ++i) {
            if (abs(a[i]-trythis) > mx && abs(a[i]-trythat) > mx &&
                abs(a[i]-joe) > mx && abs(a[i]-mama) > mx) {
                return false;
            }
        }
        return true;
    };
    int l = 0, r = 1000000001;
    while (l < r) {
        int mid = l+(r-l)/2;
        if (feasible(mid)) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << l << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
