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
    int n,m,h; cin >> n >> m >> h;
    vector<priority_queue<ll,vector<ll>,greater<ll>>> a(n);
    FOR(i,n) {
        FOR(j,m) {
            ll x; cin >> x;
            a[i].push(x);
        }
    }
    vector<vector<ll>> res(n,vector<ll>(3)); // points, penalty, index 
    FOR(i,n) {
        ll points = 0;
        ll penalty = 0;
        ll total = 0;
        while (!a[i].empty()) {
            ll x = a[i].top(); a[i].pop();
            if (total + x > h) {
                break;
            }
            points++;
            total += x;
            penalty += (total);
        }
        res[i] = {points,penalty,i};
    }
    sort(all(res),[](const vector<ll> a, const vector<ll> b) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
                return a[2] == 0;
            }
            return a[1] < b[1];
        }
        return a[0] > b[0];
    });
    int joe = -1;
    FOR(i,n) {
        if (res[i][2] == 0) {
            joe = i;
            break;
        }
    }
    cout << joe+1 << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
