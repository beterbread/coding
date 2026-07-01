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
    int n,c; cin >> n >> c;
    vector<int> a(n),b(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];
    int pos1 = 0;
    FOR(i,n) {
        if (a[i] < b[i]) {
            pos1 = -1;
            break;
        }
        else {
            pos1 += a[i] - b[i];
        }
    }
    sort(all(a));
    sort(all(b));
    int pos2 = c;
    FOR(i,n) {
        if (a[i] < b[i]) {
            pos2 = -1;
            break;
        }
        else {
            pos2 += a[i] - b[i];
        }
    }
    if (pos1 == -1 && pos2 == -1) {
        cout << -1 << '\n';
    }
    else if (pos1 == -1) {
        cout << pos2 << '\n';
    }
    else if (pos2 == -1) {
        cout << pos1 << '\n';
    }
    else {
        cout << min(pos1,pos2) << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
