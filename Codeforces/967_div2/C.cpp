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
    vector<bool> used(n,false);
    vector<vector<bool>> mat(n,vector<bool>(n,false));
    auto joe = [&](int a, int b, auto&& joe) -> void {
        cout << "? " << a << ' ' << b << endl;
        int x; cin >> x;
        used[b-1] = true;
        if (x == a) {
            mat[a-1][b-1] = true;
        }
        else {
            if (!used[x-1]) joe(a,x,joe);
            joe(x,b,joe);
        }
    };
    for (int i = 2; i <= n; ++i) {
        if (used[i-1]) continue;
        joe(1,i,joe);
    }
    cout << "! ";
    FOR(i,n) {
        FOR(j,n) { 
            if (mat[i][j]) {
                cout << i+1 << ' ' << j+1 << ' ';
            }
        }
    }
    cout << endl;
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
