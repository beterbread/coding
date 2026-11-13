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
    map<int,vector<int>> map;
    FOR(i,n) {
        map[a[i]].pb(i);
    }
    vector<char> res(n,'C');
    if (map[0].empty()) {
        cout << "YES\n";
        each(c,res) cout << c;
        cout << '\n';
        return;
    }
    else if (map[0].size() == 1) {
        cout << "NO\n";
        return;
    }
    else {
        bool tog = false;
        while (!map[0].empty()) {
            if (tog) res[map[0].back()] = 'A';
            else res[map[0].back()] = 'B';
            tog = !tog;
            map[0].pop_back();
        }
    }
    int mex_a = 1, mex_b = 1;
    for (int i = 1; i <= n+1; ++i) {
        if (map.find(i) != map.end() && map[i].size() >= 2) {
            res[map[i].back()] = 'A';
            map[i].pop_back();
            res[map[i].back()] = 'B';
            map[i].pop_back();
        }
        else {
            mex_a = i;
            mex_b = i;
            break;
        }
    }
    if (mex_a+mex_b >= 2*max(mex_a,mex_b)) {
        cout << "YES\n";
        each(c,res) cout << c;
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
