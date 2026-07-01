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
    int n,k,d,w; cin >> n >> k >> d >> w;
    vector<int> a(n);
    FOR(i,n) cin >> a[i];

    int res = 0;
    int l=0,r=0;
    while (1) {
        while (r+1<n && r-l+1<k && a[l]+d+w>=a[r+1]) {
            r++;
        }
        res++;
        if (r==n-1) break;
        l=r+1;
        r=l;
    }
    cout << res << "\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
