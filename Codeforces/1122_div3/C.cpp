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
    string a; cin >> a;
    int res = 0;
    int x = 0;
    FOR(i,n) {
        if (a[i] == '0') {
            x++;
        }
        else {
            bool check = true;
            for (int j = i+1; j < n; ++j) {
                if (a[j] == '0') {
                    check = false;
                    break;
                }
            }
            if (check) res += x;
            break;
        }
    }
    int y = 0;
    int cnt = 0;
    FOR(i,n) {
        if (a[i] == '1') {
            cnt++;
        }
        if (cnt >= 2) {
            y += a[i] == '0';
        }
    }
    cout << res << ' ' << y << '\n';
    cout << (res + y) << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
