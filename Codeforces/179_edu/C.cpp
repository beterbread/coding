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
    int n; cin >>n;
    vector<ll> a(n);
    FOR(i,n) cin >>a[i];

    vector<ll> pre(n),suf(n);
    pre[0]=1;
    suf[n-1]=1;
    for (int i = 1; i<n; i++) {
        if (a[i]==a[i-1]) pre[i]=pre[i-1]+1;
        else pre[i]=1;
    }
    for (int i = n-2; i>=0; i--) {
        if (a[i]==a[i+1]) suf[i]=suf[i+1]+1;
        else suf[i]=1;
    }
    // each(x,pre) cout << x << " ";
    // cout << '\n';
    // each(x,suf) cout << x << " ";
    // cout << '\n';
    ll res = LLONG_MAX;
    for (int i = 0; i<n; i++) {
        ll c1=0,c2=0;
        if (i>0) {
            if (a[i-1]!=a[i] || pre[i-1]!=i) {
                c1=a[i]*(i-pre[i]+1);
            }
        }
        if (i+1<n) {
            if (a[i+1]!=a[i] || suf[i+1]!=n-i-1) {
                c2=a[i]*(n-i-suf[i]);
            }
        }
        res = min(res,c1+c2);
    }
    cout << res << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
