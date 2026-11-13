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
    int n,m,L; cin >> n >> m >> L;
    vector<pair<int,int>> hurdle(n);
    FOR(i,n) cin >> hurdle[i].ff >> hurdle[i].ss;
    vector<pair<int,int>> power(m);
    FOR(i,m) cin >> power[i].ff >> power[i].ss;
    int res = 0;
    int j = 0, k = 0;
    priority_queue<int> pq;
    FOR(i,n) {
        auto [l,r] = hurdle[i];
        while (j < m && power[j].ff < l) {
            pq.push(power[j].ss);
            j++;
        }
        while (k < r-l+1) {
            if (pq.empty()) {
                cout << -1 << '\n';
                return;
            }
            res++;
            k += pq.top(); 
            pq.pop();
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
