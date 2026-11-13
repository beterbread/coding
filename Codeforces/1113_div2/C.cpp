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
    vector<int> a(2*n);
    vector<pair<int,int>> left_right(n,{-1,-1});
    FOR(i,2*n) {
        int x; cin >> x;
        x--; // 0 to n-1
        a[i] = x;
        if (left_right[x].ff == -1) {
            left_right[x].ff = i;
        }
        else {
            left_right[x].ss = i;
        }
    }
    priority_queue<pair<ll,int>> pq;
    FOR(i,n) {
        int l = left_right[i].ff, r = left_right[i].ss;
        pq.push({r-l+1,i});
    }
    vector<bool> used(2*n,false);
    ll res = 0;
    while (!pq.empty()) {
        auto [range,i] = pq.top(); pq.pop();
        int l = left_right[i].ff, r = left_right[i].ss;
        if (used[l] || used[r]) {
            res += (!used[l] + !used[r]);
        }
        else {
            res += (range * range);
            for (int j = l; j <= r; ++j) used[j] = true;
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
