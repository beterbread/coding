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
    int n,m; cin >>n>>m;
    string s; cin >>s;
    vector<vector<ll>> mat(n,vector<ll>(m));
    FOR(i,n) FOR(j,m) cin >>mat[i][j];

    vector<ll> row(n),col(m);
    FOR(i,n) {
        FOR(j,m) {
            row[i]+=mat[i][j];
            col[j]+=mat[i][j]; 
        }
    }

    int x=0,y=0;
    each(c,s) {
        if (c=='D') { 
            ll add = (0-row[x])-mat[x][y];
            mat[x][y] = 0-row[x];
            row[x]+=add;
            col[y]+=add;
            x++;
        }
        else {
            ll add = (0-col[y])-mat[x][y];
            mat[x][y] = 0-col[y];
            row[x]+=add;
            col[y]+=add;
            y++;
        }
    }
    mat[n-1][m-1] = 0-row[n-1];

    FOR(i,n) {
        FOR(j,m) {
            cout << mat[i][j] << " ";
        }
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
