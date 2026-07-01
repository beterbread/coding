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
    int n,x; cin >>n>>x;

    ll res = 0;
    int place = 0, zeros = n;
    do {
        int bit = x&1;
        if (!zeros) {
            if (bit) res += (1LL<<place);
        }
        else if (bit) {
            if (zeros&1) {
                res += (1LL<<place)*zeros;
                zeros=0;
            }
            else {
                if (zeros-1>0) {
                    res += (1LL<<place)*(zeros-1);
                    zeros-=(zeros-1);
                }
                else if (zeros+1<=n) {
                    res += (1LL<<place)*(zeros+1);
                    zeros=0;
                }
                else {
                    cout << "-1\n";
                    return;
                }
            }
        }
        else {
            if (!(zeros&1)) {
                res += (1LL<<place)*zeros;
                zeros=0;
            }
            else {
                if (zeros-1>0) {
                    res += (1LL<<place)*(zeros-1);
                    zeros-=(zeros-1);
                }
                else if (zeros+1<=n) {
                    res += (1LL<<place)*(zeros+1);
                    zeros=0;
                }
                else {
                    cout << "-1\n";
                    return;
                }
            }
        }
        x>>=1;
        place++;
        cout << res << " " << zeros << "\n";
    } while (x);
    if (zeros>0) {
        if (zeros&1) {
            if (zeros+1>n) {
                cout << "-1\n";
                return;
            }
            res += (1LL<<place)*(zeros+1);
        }
        else {
            res += (1LL<<place)*(zeros);
        }
    }
    cout << res << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
