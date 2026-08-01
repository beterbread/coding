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
    ll x1,y1; cin >> x1 >> y1;
    ll x2,y2; cin >> x2 >> y2;
    ll x3,y3; cin >> x3 >> y3;
    ll x4,y4; cin >> x4 >> y4;
    vector<ll> joe = {x1,x2,x3,x4};
    vector<ll> mama = {y1,y2,y3,y4};
    sort(all(joe));
    sort(all(mama));
    cout << (abs(joe[0]-joe[3]) * abs(mama[0]-mama[3])) << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
