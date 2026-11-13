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
    string s; cin >> s;
    if (s == "first") {
        int n; cin >> n;
        vector<int> a(n);
        FOR(i,n) cin >> a[i];
        string res = "";
        FOR(i,n) {
            res.pb((a[i]-1)+'a');
        }
        cout << res << '\n';
    }
    else {
        string joe; cin >> joe;
        cout << joe.length() << '\n';
        each(c,joe) {
            cout << ((c-'a')+1) << ' ';
        }
        cout << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
