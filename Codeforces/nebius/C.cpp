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
    int n,x,p; cin >> n >> x >> p;

    ll total = 0;
    for (int i = 1; i<=min(n*(int)sqrt(n),p); i++) {
        total += i;
        int joe = (x+(total%n))%n;
        if (joe==0) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
