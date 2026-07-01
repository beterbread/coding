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
    vector<int> a(n),b(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];
    vector<pair<int,int>> pre(n),suf(n);
    pre[0] = {a[0],b[0]};
    suf[n-1] = {a[n-1],b[n-1]};
    for (int i = 1; i < n; i++) {
        vector<int> S = {pre[i-1].ff,pre[i-1].ss,a[i],b[i]};
        sort(all(S));
        pre[i].ff = S[1];
        pre[i].ss = S[2];
    }
    for (int i = n-2; i >= 0; i--) {
        vector<int> S = {suf[i+1].ff,suf[i+1].ss,a[i],b[i]};
        sort(all(S));
        suf[i].ff = S[1];
        suf[i].ss = S[2];
    }
    // cout << "pre\n";
    // each(x,pre) cout << x.ff << ' ';
    // cout << '\n';
    // each(x,pre) cout << x.ss << ' ';
    // cout << '\n';
    // cout << "suf\n";
    // each(x,suf) cout << x.ff << ' ';
    // cout << '\n';
    // each(x,suf) cout << x.ss << ' ';
    // cout << '\n';
    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
        {
            vector<int> S = {pre[i].ff,pre[i].ss};
            if (i < n-1) S = {suf[i+1].ff,suf[i+1].ss,S[0],S[1]};
            sort(all(S));
            if (S.size()==2) res = max(res,S[0]);
            else res = max(res,S[1]);
        }
        {
            vector<int> S = {suf[i].ff,suf[i].ss};
            if (i > 0) S = {pre[i-1].ff,pre[i-1].ss,S[0],S[1]};
            sort(all(S));
            if (S.size()==2) res = max(res,S[0]);
            else res = max(res,S[1]);
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
