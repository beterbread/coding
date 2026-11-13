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
    int n; cin >> n;
    vector<int> bits(19,0);
    for (int i = 1; i <= n; ++i) {
        int x = i;
        int place = 0;
        while (x) {
            if (x&1) {
                bits[place]++;
            }
            x >>= 1;
            place++;
        }
    }
    // FOR(i,19) cout << bits[i] << ' ';
    // cout << '\n';
    vector<bool> res(n,false);
    vector<int> temp(19,0);
    for (int i = n; i >= 1; --i) {
        int x = i;
        int place = 0;
        while (x) {
            if (x&1) {
                temp[place]++;
            }
            x >>= 1;
            place++;
        }
        bool good = false;
        for (int p = 17; p >= 0; --p) {
            if (temp[p]) {
                good = bits[p+1] % 2 == 0;
                break;
            }
        }
        if (good) {
            res[i-1] = true;
            for (int p = 17; p >= 0; --p) {
                if (temp[p]) {
                    bits[p]--;
                    bits[p+1]++;
                }
            }
        }
        FOR(i,19) temp[i] = 0;
    }
    FOR(i,n) cout << (res[i] ? '1' : '0') << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
