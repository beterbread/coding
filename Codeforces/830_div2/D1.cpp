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
    int q; cin >> q;
    set<long long> set;
    map<long long,long long> map;
    while (q--) {
        char op; cin >> op;
        long long x; cin >> x;
        if (op=='+') {
            set.insert(x);
        }
        else {
            if (map.find(x) == map.end()) map[x] = x;
            long long y = map[x];
            while (set.find(y) != set.end()) {
                y += x;
            }
            map[x] = y;
            cout << y << '\n';
        }
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
