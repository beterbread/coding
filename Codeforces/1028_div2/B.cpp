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

long long modpow(long long x, long long n, long long m) {
    long long result = 1;
    x = x % m; 
    while (n > 0) {
        if (n % 2 == 1) result = (result * x) % m;  
        x = (x * x) % m; 
        n /= 2;
    }
    return result;
}

void solve() {
    int n; cin >>n;
    vector<ll> p(n), q(n);
    FOR(i,n) cin >>p[i];
    FOR(i,n) cin >>q[i];

    vector<pair<ll,ll>> mxp(n), mxq(n);
    mxp[0] = {p[0],0};
    mxq[0] = {q[0],0};
    for (int i = 1; i < n; i++) {
        if (p[i] > mxp[i-1].ff) mxp[i] = {p[i],i};
        else mxp[i] = mxp[i-1];
        if (q[i] > mxq[i-1].ff) mxq[i] = {q[i],i};
        else mxq[i] = mxq[i-1];
    }

    ll mod = 998244353;
    vector<ll> r(n);
    FOR(i,n) {
        int mx1 = mxp[i].ss;
        int pos1 = p[mx1];
        int mx2 = mxq[i].ss;
        int pos2 = q[mx2];
        if (pos1>pos2) {
            ll joe = modpow(2,p[mx1],mod) + modpow(2,q[i-mx1],mod);
            r[i] = joe%mod;
        }
        else if (pos2>pos1) {
            ll joe = modpow(2,p[i-mx2],mod) + modpow(2,q[mx2],mod);
            r[i] = joe%mod;
        }
        else {
            if (q[i-mx1]>p[i-mx2]) {
                ll joe = modpow(2,p[mx1],mod) + modpow(2,q[i-mx1],mod);
                r[i] = joe%mod;
            }
            else {
                ll joe = modpow(2,p[i-mx2],mod) + modpow(2,q[mx2],mod);
                r[i] = joe%mod;
            }
        }
    }

    each(x,r) cout << x << " ";
    cout << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
