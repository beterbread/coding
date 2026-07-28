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
    ld d,h; cin >> d >> h;
    unordered_set<ld> set;
    FOR(i,n) {
        ld x; cin >> x;
        set.insert(x);
    }
    vector<ld> a(all(set));
    sort(all(a));
    ld res = 0;
    FOR(i,n) {
        res += (d*h)/2;
        if (i+1 < n && a[i+1] < a[i] + h) {
            ld height = a[i] + h - a[i+1];
            ld width = (height/h) * d;
            res -= (height*width)/2;
        }
    }
    cout << fixed << setprecision(7) << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
