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
    set<set<int>> set;
    vector<pair<int,int>> a(n-1);
    FOR(i,n-1) {
        int x,y; cin >> x >> y;
        set[x].insert(y);
        a[i] = {x,y};
    }
    int res = -1;
    FOR(i,n-1) {
        auto [x,y] = a[i];
        if (set.find(x) != set.end() && set[x].find(y) != set[x].end()) {
            
        }
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
