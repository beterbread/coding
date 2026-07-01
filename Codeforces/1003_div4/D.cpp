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
    int n,m; cin >> n >> m;
    priority_queue<pair<ll,vector<int>>> pq;
    FOR(i,n) {
        ll pos = 0;
        vector<int> tmp(m);
        FOR(j,m) {
            cin >> tmp[j];
            pos+=tmp[j];
        }
        pq.push({pos,tmp});
    }
    int cur=n*m;
    ll res = 0;
    while (!pq.empty()) {
        for (int x : pq.top().ss) {
            res+=ll(x)*ll(cur);
            cur--;
        }
        pq.pop();
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
