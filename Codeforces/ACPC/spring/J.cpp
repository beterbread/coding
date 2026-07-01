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
    int n,a; cin >> n >> a;
    double s,t; cin >> s >> t;
    double res = sqrt(s*s+t*t);
    s/=8;
    t/=8;
    FOR(i,n) {
        double x,y; cin >> x >> y;
        int cost; cin >> cost;
        if (cost>a) continue;
        double pos = 0;
        pos += sqrt(x*x+y*y);
        x/=8;
        y/=8;
        pos += sqrt((x-s)*(x-s)+(y-t)*(y-t));
        res = min(res,pos);
    }
    cout << fixed << setprecision(10) << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
