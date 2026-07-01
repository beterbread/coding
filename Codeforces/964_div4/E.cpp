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

vector<int> a;
void solve() {
    int l,r; cin >> l >> r;
    int ops = a[l] - a[l-1];
    ops *= 2;
    ops += a[r] - a[l];
    cout << ops << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    a.resize(200001);
    auto joe = [&](int x) -> int {
        int res = 0;
        while (x > 0) {
            x = floor(double(x)/3);
            res++;
        }
        return res;
    };
    a[0] = 0;
    for (int i = 1; i <= 200000; i++) a[i] = joe(i);
    for (int i = 2; i <= 200000; i++) a[i] += a[i-1];
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
