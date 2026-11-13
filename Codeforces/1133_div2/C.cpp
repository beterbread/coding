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
    int mx = -1;
    FOR(i,n-1) {
        mx = max(mx,abs(a[i]-a[i+1]));
    }
    int cnt = 0;
    FOR(i,n-1) {
        if (abs(a[i]-a[i+1]) == mx) {
            cnt++;
        }
    }
    if (cnt > 2) {
        cout << mx << '\n';
    }
    else if (cnt == 2) {
        int l = -1, r = -1;
        FOR(i,n-1) {
            if (abs(a[i]-a[i+1]) == mx) {
                if (cnt == 2) {
                    l = i+1;
                }
                else if (cnt == 1) {
                    r = i;
                }
                cnt--;
            } 
            if (cnt == 0) {
                break;
            }
        }
        int mx_sofar = max(abs(a[l-1]-(2*a[r])),abs(a[r+1]-(2*a[l])));
        for (int i = l; i < r; ++i) {
            mx_sofar = max(mx_sofar,abs(a[i]-a[i+1])*2);
        }
        for (int i = 0; i < l-1; ++i) {
            mx_sofar = max(mx_sofar, abs(a[i]-a[i+1]));
        }
        for (int i = r+1; i < n-1; ++i) {
            mx_sofar = max(mx_sofar, abs(a[i]-a[i+1]));
        }
        cout << min(mx_sofar,mx) << '\n';
    }
    else if (cnt == 1) {
        int f = -1, s = -1;
        FOR(i,n-1) {
            if (abs(a[i]-a[i+1]) == mx) {
                f = i, s = i+1;
                break;
            }
        }
        
        // double a[f]
        int tmpf = a[f];
        a[f] *= 2;
        int trythis = -1;
        FOR(i,n-1) {
            trythis = max(trythis,abs(a[i]-a[i+1]));
        }
        a[f] = tmpf;

        // double a[s]
        int tmps = a[s];
        a[s] *= 2;
        int trythat = -1;
        FOR(i,n-1) {
            trythat = max(trythat,abs(a[i]-a[i+1]));
        }
        a[s] = tmps;

        vector<int> pre(n),suf(n);
        pre[0] = 0;
        for (int i = 1; i < n; ++i) {
            pre[i] = max(pre[i-1],abs(a[i]-a[i-1]));
        }
        suf[n-1] = 0;
        for (int i = n-2; i >= 0; --i) {
            suf[i] = max(suf[i+1],abs(a[i]-a[i+1]));
        }

        int res = mx;
        int mx_sofar = -1;
        for (int i = s; i < n-1; ++i) {
            if (abs(a[i]-a[i+1])*2 >= mx) {
                break;
            }
            mx_sofar = max(mx_sofar,abs(a[i]-a[i+1])*2);
            int joe = max(abs(a[f]-(2*a[i+1])),(i+2 < n ? abs((2*a[s])-a[i+2]) : 0));
            joe = max(joe, pre[f]);
            joe = max(joe, (i+2 < n ? suf[i+2] : 0));
            res = min(res,max(mx_sofar,joe));
        }
        mx_sofar = -1;
        for (int i = f; i > 0; --i) {
            if (abs(a[i]-a[i-1])*2 >= mx) {
                break;
            }
            mx_sofar = max(mx_sofar,abs(a[i]-a[i-1])*2);
            int joe = max(abs(a[s]-(2*a[i-1])),(i-2 >= 0 ? abs((2*a[f])-a[i-2]) : 0));
            joe = max(joe, (i-2 >= 0 ? pre[i-2] : 0));
            joe = max(joe, suf[f+1]);
            res = min(res,max(mx_sofar,joe));
        }
        cout << min(res,min(trythis,trythat)) << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
