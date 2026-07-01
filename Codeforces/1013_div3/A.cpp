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
    vector<int> joe(n);
    FOR(i,n) cin >> joe[i];
    unordered_map<int,int> map;
    FOR(i,n) {
        int a = joe[i];
        map[a]++;
        if (map[0]>=3 && map[1]>=1 && map[2]>=2 && map[3]>=1 && map[5]>=1) {
            cout << i+1 << '\n';
            return;
        }
    }
    cout << "0\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
