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
    string s; cin >> s;
    vector<int> a(m);
    FOR(i,m) cin >> a[i];
    string c; cin >> c;
    priority_queue<char,vector<char>,greater<char>> pq;
    each(x,c) pq.push(x);
    set<int> set(all(a));
    each(x,set) {
        s[x-1] = pq.top();
        pq.pop();
    }
    cout << s << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
