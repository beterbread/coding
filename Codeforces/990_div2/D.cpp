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
    map<int,int> map;
    each(x,a) {
        map[x]++;
    }
    vector<int> res,res2;
    each(x,a) {
        if (x == map.begin()->ff) {
            res.pb(map.begin()->ff);
            map.begin()->ss--;
            if (map.begin()->ss == 0) {
                map.erase(map.begin());
            }
        }
        else {
            map[x]--;
            if (map[x] == 0) {
                map.erase(x);
            }
            res2.pb(x+1);
        }
    }
    sort(all(res2));
    FORD(i,res.size()) {
        if (res2.empty()) break;
        if (res[i] > res2[0]) {
            res2.pb(res.back()+1);
            res.pop_back();
        }
        else {
            break;
        }
    }
    sort(all(res2));
    each(x,res) cout << x << ' ';
    each(x,res2) cout << x << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
