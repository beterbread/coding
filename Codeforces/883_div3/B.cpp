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
    vector<string> grid(3);
    FOR(i,3) cin >> grid[i];
    auto joe = [&](char c) -> bool {
        return 
            (grid[0][0] == c && grid[0][1] == c && grid[0][2] == c) ||
            (grid[1][0] == c && grid[1][1] == c && grid[1][2] == c) ||
            (grid[2][0] == c && grid[2][1] == c && grid[2][2] == c) ||
            (grid[0][0] == c && grid[1][0] == c && grid[2][0] == c) ||
            (grid[0][1] == c && grid[1][1] == c && grid[2][1] == c) ||
            (grid[0][2] == c && grid[1][2] == c && grid[2][2] == c) ||
            (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c) ||
            (grid[0][2] == c && grid[1][1] == c && grid[2][0] == c);
    };
    bool x = joe('X');
    bool y = joe('O');
    bool z = joe('+');
    if (x) {
        cout << "X\n";
    }
    else if (y) {
        cout << "O\n";
    }
    else if (z) {
        cout << "+\n";
    }
    else {
        cout << "DRAW\n";
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
