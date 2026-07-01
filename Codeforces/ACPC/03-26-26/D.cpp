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
    ll n,x; cin >> n >> x;
    
    int res = 0;
    while (1) {
        string mama = to_string(x);
        if (mama.length()==n) {
            cout << res << '\n';
            return;
        }
        ll joe = -1;
        ll y = x;
        while (y) {
            joe = max(joe,y%10);
            y/=10;
        }
        if (joe==1) {
            cout << "-1\n";
            return;
        }
        x*=joe;
        res++;
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
