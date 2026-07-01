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

int joe(int n, int m){
    int res = 1;
    while (n!=1){
        n = (n+1)/2;
        res++;
    }
    while (m!=1){
        m = (m+1)/2;
        res++;
    }
    return res;
}

void solve() {
    int n,m,a,b; cin >>n>>m>>a>>b;
    
    cout << min(joe(n,min(b,m-b+1)),joe(min(a,n-a+1),m)) << endl;
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    
    return 0; 
} 