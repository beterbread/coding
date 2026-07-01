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
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    ll sum = 0;
    multiset<int> set;
    FOR(i,n) {
        sum += a[i];
        set.insert(a[i]);
    }
    vector<int> res;
    FOR(i,n) {
        set.erase(set.find(a[i]));
        if (*prev(set.end()) == sum-a[i]-*prev(set.end())) {
            res.pb(i+1);
        }
        set.insert(a[i]);
    }
    cout << res.size() << '\n';
    each(x,res) cout << x << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
