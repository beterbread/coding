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
    int n,m,k; cin >>n>>m>>k;

    vector<vector<int>> grid(n,vector<int>(m));
    int x = 1;
    FOR(i,n) {
        FOR(j,m) {
            grid[i][j]=x;
            x++;
            if(x==k+1) x=1;
        }
    }
    for (int i = 1; i < n; i+=2) {
        FOR(j,m) {
            if (grid[i][j]==grid[i-1][j]) {
                rotate(grid[i].begin(),grid[i].begin()+1,grid[i].end());
                break;
            }
        }
    }
    
    each(x,grid) {
        each(y,x) cout << y << " ";
        cout << "\n";
    }
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	int t; cin >> t;
    while (t--) solve();
	
	return 0; 
} 
