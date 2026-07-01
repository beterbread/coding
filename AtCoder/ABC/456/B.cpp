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
    vector<int> a(6),b(6),c(6);
    FOR(i,6) cin >> a[i];
    FOR(i,6) cin >> b[i];
    FOR(i,6) cin >> c[i];
    double count = 0;
    FOR(i,6) {
        FOR(j,6) {
            FOR(k,6) {
                vector<int> joe = {a[i],b[j],c[k]};
                sort(all(joe));
                if (joe[0]==4 && joe[1]==5 && joe[2]==6) count+=(1.0/6.0);
            }
        }
    }
    double res = count/36.0;
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
