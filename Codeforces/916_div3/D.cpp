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
    // int n; cin >> n;
    // vector<ll> a(n),b(n),c(n);
    // FOR(i,n) cin >> a[i];
    // FOR(i,n) cin >> b[i];
    // FOR(i,n) cin >> c[i];
    // vector<ll> apre(n),asuf(n);
    // vector<ll> bpre(n),bsuf(n);
    // vector<ll> cpre(n),csuf(n);
    // auto makepre = [&](vector<ll>& pre, const vector<ll>& og) -> void {
    //     pre[0] = og[0];
    //     for (int i = 1; i < n; i++) {
    //         pre[i] = max(og[i],pre[i-1]);
    //     }
    // };
    // auto makesuf = [&](vector<ll>& suf, const vector<ll>& og) -> void {
    //     suf[n-1] = og[n-1];
    //     for (int i = n-2; i >= 0; i--) {
    //         suf[i] = max(og[i],suf[i+1]);
    //     }
    // };
    // makepre(apre,a); makesuf(asuf,a);
    // makepre(bpre,b); makesuf(bsuf,b);
    // makepre(cpre,c); makesuf(csuf,c);
    // ll res = 0;
    // for (int i = 1; i < n-1; i++) {
    //     res = max(res,a[i]+bpre[i-1]+csuf[i+1]);
    //     res = max(res,a[i]+cpre[i-1]+bsuf[i+1]);
    //     res = max(res,b[i]+apre[i-1]+csuf[i+1]);
    //     res = max(res,b[i]+cpre[i-1]+asuf[i+1]);
    //     res = max(res,c[i]+apre[i-1]+bsuf[i+1]);
    //     res = max(res,c[i]+bpre[i-1]+asuf[i+1]);
    // }
    // cout << res << '\n';

    // intended solution: take 3 maximums from each array and find the max result out of the 3^3 possibilities
    int n; cin >> n;
    vector<int> a(n),b(n),c(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];
    FOR(i,n) cin >> c[i];
    vector<pair<int,int>> amx(n),bmx(n),cmx(n);
    FOR(i,n) {
        amx[i] = {a[i],i};
        bmx[i] = {b[i],i};
        cmx[i] = {c[i],i};
    }
    sort(rall(amx)); sort(rall(bmx)); sort(rall(cmx));
    int res = 0;
    FOR(i,3) {
        FOR(j,3) {
            FOR(k,3) {
                int ii = amx[i].ss, jj = bmx[j].ss, kk = cmx[k].ss;
                if (ii != jj && jj != kk && ii != kk) {
                    res = max(res,amx[i].ff+bmx[j].ff+cmx[k].ff);
                }
            }
        }
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
