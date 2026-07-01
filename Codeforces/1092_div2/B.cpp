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

ll one(ll t, ll h, ll u) {
    ll res = 0;
    // T+U=4
    ll joe = min(t,u);
    res += joe*4;
    t-=joe;
    u-=joe;
    // T+T=5
    joe = t%2==0 ? t : t-1;
    res += (joe/2)*5;
    t-=joe;
    // T+H=5
    joe = min(t,h);
    res += joe*5;
    t-=joe;
    h-=joe;
    // remaining = 3
    res += (t+h+u)*3;  
    return res;
}

ll two(ll t, ll h, ll u) {
    ll res = 0;
    // T+U=4
    ll joe = min(t,u);
    res += joe*4;
    t-=joe;
    u-=joe;
    // T+H=5
    joe = min(t,h);
    res += joe*5;
    t-=joe;
    h-=joe;
    // T+T=5
    joe = t%2==0 ? t : t-1;
    res += (joe/2)*5;
    t-=joe;
    // remaining = 3
    res += (t+h+u)*3;  
    return res;
}

ll three(ll t, ll h, ll u) {
    ll res = 0;
    // T+H=5
    ll joe = min(t,h);
    res += joe*5;
    t-=joe;
    h-=joe;
    // T+T=5
    joe = t%2==0 ? t : t-1;
    res += (joe/2)*5;
    t-=joe;
    // T+U=4
    joe = min(t,u);
    res += joe*4;
    t-=joe;
    u-=joe;
    // remaining = 3
    res += (t+h+u)*3;  
    return res;
}

ll four(ll t, ll h, ll u) {
    ll res = 0;
    // T+H=5
    ll joe = min(t,h);
    res += joe*5;
    t-=joe;
    h-=joe;
    // T+U=4
    joe = min(t,u);
    res += joe*4;
    t-=joe;
    u-=joe;
    // T+T=5
    joe = t%2==0 ? t : t-1;
    res += (joe/2)*5;
    t-=joe;
    // remaining = 3
    res += (t+h+u)*3;  
    return res;
}

ll five(ll t, ll h, ll u) {
    ll res = 0;
    // T+T=5
    ll joe = t%2==0 ? t : t-1;
    res += (joe/2)*5;
    t-=joe;
    // T+H=5
    joe = min(t,h);
    res += joe*5;
    t-=joe;
    h-=joe;
    // T+U=4
    joe = min(t,u);
    res += joe*4;
    t-=joe;
    u-=joe;
    // remaining = 3
    res += (t+h+u)*3;  
    return res;
}

ll six(ll t, ll h, ll u) {
    ll res = 0;
    // T+T=5
    ll joe = t%2==0 ? t : t-1;
    res += (joe/2)*5;
    t-=joe;
    // T+U=4
    joe = min(t,u);
    res += joe*4;
    t-=joe;
    u-=joe;
    // T+H=5
    joe = min(t,h);
    res += joe*5;
    t-=joe;
    h-=joe;
    // remaining = 3
    res += (t+h+u)*3;  
    return res;
}

void solve() {
    ll t,h,u; cin >> t >> h >> u;
    ll res = LLONG_MAX;
    res = min(res,one(t,h,u));
    res = min(res,two(t,h,u));
    res = min(res,three(t,h,u));
    res = min(res,four(t,h,u));
    res = min(res,five(t,h,u));
    res = min(res,six(t,h,u));
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
