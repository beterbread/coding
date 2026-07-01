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
    int p; cin >> p; 
    p--; // zero indexing
    int og=a[p]; 
    int cnt1=0, cnt2=0;
    for (int i=p+1; i<n; i++) {
        if (i==n-1) {
            if (a[i]!=og) cnt1++;
        }
        else if (a[i]!=a[i+1]) {
            cnt1++;
        }
    }
    for (int i=p-1; i>=0; i--) {
        if (i==0) {
            if (a[i]!=og) cnt2++;
        }
        else if (a[i]!=a[i-1]) {
            cnt2++;
        }
    }
    int res=max(cnt1,cnt2);
    if (res&1) res++;
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
