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
    if (n == 1) {
        return void(cout << 1 << '\n');
    }
    ll sum = n*2-1;
    vector<bool> used(n+1);
    vector<int> res(n);
    used[n] = true;
    used[n-1] = true;
    res[0] = n;
    res[1] = n-1;
    int high = n-2, low = 1;
    bool tog = false;
    for (int i = 2; i < n; ++i) {
        int want = tog ? high : low;
        high -= tog;
        low += !tog;
        tog = !tog;
        int mod = sum % n;
        int pos = mod >= want ? want + n - mod : want - mod;
        if (used[pos]) {
            return void(cout << -1 << '\n');
        }
        used[pos] = true;
        res[i] = pos;
        sum += pos;
    }
    each(x,res) cout << x << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
