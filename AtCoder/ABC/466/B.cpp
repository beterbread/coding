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
    int n,m; cin >> n >> m;
    unordered_map<int,int> map;
    while (n--) {
        int c,s; cin >> c >> s;
        map[c] = max(map[c],s);
    }
    for (int i = 1; i <= m; ++i) {
        if (map.find(i) == map.end()) {
            cout << "-1 ";
        }
        else {
            cout << map[i] << ' ';
        }
    }
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
