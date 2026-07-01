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
    ll sum = 0, cur = 0;
    int l=0, r=0;
    while (r < n) {
        if (r-l+1 < k) {
            cur += a[r];
            r++;
            continue;
        }
        cur += a[r];
        sum += cur;
        cur -= a[l];
        l++;
        r++;
    }
    ld res = ld(sum)/ld(n-k+1);
    cout << fixed << setprecision(6) << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
