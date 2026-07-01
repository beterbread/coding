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
    unordered_map<int,int> occur;
    unordered_map<int,ll> ops;
    occur.reserve(n * 60);
    ops.reserve(n * 60);
    each(x,a) {
        if (x==1) {
            occur[1]++;
            occur[2]++;
            ops[1] += 0;
            ops[2] += 1;
            continue;
        }
        occur[x]++;
        ops[x] += 0;
        int cost = 0;
        while (x!=1) {
            if (x&1) x++;
            else x/=2;
            cost++;
            occur[x]++;
            ops[x] += cost;
        }
    }
    ll res = INT_MAX;
    each(x,occur) {
        if (x.ss == n) {
            res = min(res,ops[x.ff]);
        }
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    // 1 to 1,000,000,000
    // int x; cin >> x;
    // while (x!=1) {
    //     if (x&1) x++;
    //     else x/=2;
    //     cout << x << ' ';
    // }
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
