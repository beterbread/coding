#include <bits/stdc++.h> 
using namespace std; 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int INF_INT = 1e9;
const ld EPS = 1e-9;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#define popcount(x) __builtin_popcount(x)
#define parity(x) __builtin_parity(x)
#define clzll(x) __builtin_clzll(x)
#define ctzll(x) __builtin_ctzll(x)
#define popcountll(x) __builtin_popcountll(x)
#define parityll(x) __builtin_parityll(x)

ll rec(ll l, ll r, ll t, ll b, ll low, ll high, ll x, ll y) {
    if (r-l == 1) {
        if (l==x && t==y) 
            return low;
        if (l==x && b==y)
            return high;
        if (r==x && t==y)
            return high-1;
        if (r==x && b==y)
            return low+1;
    }

    ll q = (high-low+1)>>2;
    ll mid = (r-l)>>1;
    // top left
    if (x>=l && x<=l+mid && y>=t && y<=t+mid) 
        return rec(l,l+mid,t,t+mid,low,low+q-1,x,y);
    // bottom right
    if (x>=l+mid+1 && x<=r && y>=t+mid+1 && y<=b) 
        return rec(l+mid+1,r,t+mid+1,b,low+q,low+2*q-1,x,y);
    // top right
    if (x>=l+mid+1 && x<=r && y>=t && y<=t+mid) 
        return rec(l+mid+1,r,t,t+mid,low+2*q,low+3*q-1,x,y);
    // bottom left
    if (x>=l && x<=l+mid && y>=t+mid+1 && y<=b) 
        return rec(l,l+mid,t+mid+1,b,low+3*q,high,x,y);
    return -1;
}

pair<ll,ll> rec2(ll l, ll r, ll t, ll b, ll low, ll high, ll d) {
    if (r-l == 1) {
        if (d == low) 
            return {l,t};
        if (d == high)
            return {l,b};
        if (d == high-1)
            return {r,t};
        if (d == low+1)
            return {r,b};
    }

    ll q = (high-low+1)>>2;
    ll mid = (r-l)>>1;
    // top left
    if (d>=low && d<=low+q-1) 
        return rec2(l,l+mid,t,t+mid,low,low+q-1,d);
    // bottom right
    if (d>=low+q && d<=low+2*q-1)
        return rec2(l+mid+1,r,t+mid+1,b,low+q,low+2*q-1,d);
    // top right
    if (d>=low+2*q && d<=low+3*q-1)
        return rec2(l+mid+1,r,t,t+mid,low+2*q,low+3*q-1,d);
    // bottom left
    if (d>=low+3*q && d<=high) 
        return rec2(l,l+mid,t+mid+1,b,low+3*q,high,d);
    return {-1,-1};
}

void solve() {
    int n, q; cin >> n >> q;

    ll pw = 1LL<<n;
    ll pww = 1LL<<(2*n);
    while(q--) {
        string op; cin >> op;
        if (op == "->") {
            ll x,y; cin >> x >> y;
            cout << rec(1,pw,1,pw,1,pww,x,y) << "\n";
        }
        else {
            ll d; cin >> d;
            auto p = rec2(1,pw,1,pw,1,pww,d);
            cout << p.ff << " " << p.ss << "\n";
        }
    }
}

int main() 
{ 
    fast_io

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0; 
} 
