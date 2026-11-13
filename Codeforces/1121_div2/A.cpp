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
    deque<int> idx;
    FOR(i,n) {
        if (a[i] != i+1) {
            idx.pb(i);
        }
    }
    while (idx.size() > 1) {
        int tmp = a[idx.front()];
        a[idx.front()] = a[idx.back()];
        a[idx.back()] = tmp;
        idx.pop_front();
        idx.pop_back();
    }
    cout << (is_sorted(all(a)) ? "YES" : "NO") << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
