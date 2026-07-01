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
    int a1,a2,b1,b2; cin >> a1 >> a2 >> b1 >> b2;
    int res = 0;
    int x=0,y=0;
    if (b1 > a1) x++;
    else if (a1 > b1) y++;
    if (b2 > a2) x++;
    else if (a2 > b2) y++;
    if (y > x) res++;
    x=0, y=0;
    if (b2 > a1) x++;
    else if (a1 > b2) y++;
    if (b1 > a2) x++;
    else if (a2 > b1) y++;
    if (y > x) res++;
    cout << res*2 << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
