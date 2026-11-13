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
    sort(rall(a));
    map<int,int> map;
    deque<int> res;
    int k = 0;
    FOR(i,n) {
        if (map.find(a[i]) == map.end()) {
            k++;
            res.push_front(a[i]);
            map[a[i]]++;
        }
        else {
            if (map[a[i]] == 1) {
                k++;
            }
            res.push_back(a[i]);
            map[a[i]]++;
        }
    }
    cout << k << '\n';
    FOR(i,n) cout << res[i] << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
