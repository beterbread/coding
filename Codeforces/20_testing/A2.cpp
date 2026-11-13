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
        FORD(i,n) {
            int x = a[i];
            while (x) {
                res.pb((x%10)+'a');
                x /= 10;
            }
            if (i != 0) res.pb('#');
        }
        cout << res << '\n';
    }
    else {
        string joe; cin >> joe;
        int n = joe.length();
        int sz = 0;
        string res = "";
        FORD(i,n) {
            char c = joe[i];
            if (c == '#') {
                res.pb(' ');
                sz++;
            }
            else {
                res.pb((c-'a')+'0');
            }
        }
        cout << sz+1 << '\n';
        cout << res << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
