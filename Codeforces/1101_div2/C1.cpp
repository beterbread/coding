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
    ll n,x,s; cin >> n >> x >> s;
    string u; cin >> u;
    ll E_LEFT = 0, I_LEFT = 0, A_LEFT = 0;
    each(c,u) {
        if (c=='E') E_LEFT++;
        else if (c=='I') I_LEFT++;
        else A_LEFT++;
    }
    ll AE = 0;
    int res = 0;
    FOR(i,n) {
        // cout << x << ' ' << AE << '\n';
        // ALWAYS OPTIMAL(?) TO SEAT AN INTROVERT IF THERE'S AN EMPTY TABLE, AE CAN FOLLOW AFTER
        if (u[i]=='I') { // SEAT THIS INTROVERT FIRST
            if (x > 0) {
                x--;
                AE += (s-1);
                res++;
            }
            I_LEFT--;
        }
        if (u[i]=='A') {
            if (AE == 0) {
                x--;
                AE += (s-1);
                res++;
            }
            else if (AE > 0) {
                if (E_LEFT > AE) {
                    x--;
                    AE += (s-1);
                    res++;
                }
                else {
                    AE--;
                    res++;
                }
            }
            A_LEFT--;
        }
        if (u[i]=='E') {
            if (AE > 0) {
                AE--;
                res++;
            }
            E_LEFT--;
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
