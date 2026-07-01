#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int INF_INT = 1e9;
const ld EPS = 1e-9;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#define popcount(x) __builtin_popcount(x)
#define parity(x) __builtin_parity(x)
#define clzll(x) __builtin_clzll(x)
#define ctzll(x) __builtin_ctzll(x)
#define popcountll(x) __builtin_popcountll(x)
#define parityll(x) __builtin_parityll(x)

// assume s1 is longer
string XOR(string& s1, string& s2) {
    string res = "";
    int n1 = s1.length();
    int n2 = s2.length();
    FOR(i, n2) {
        char x = s2[i], y = s1[i + n1 - n2];
        if (x == y) res.pb('0');
        else res.pb('1');
    }
    return s1.substr(0, n1 - n2) + res;
}

// return true if s1 >= s2
bool foo(string& s1, string& s2) {
    int n = s1.length();
    FOR(i, n) {
        if (s1[i] != s2[i]) return s1[i] == '1';
    }
    return true;
}

void solve() {
    string s; cin >> s;
    
    int n = s.length();
    // first interval always 1 to n
    int idx = -1;
    FOR(i, n) { // find left most zero
        if (s[i] == '0'){
            idx = i;
            break;
        }
    }
    
    if (idx == -1) { // all ones
        cout << "1 " << n << " 1 1\n";
        return;
    }
    
    string res = "";
    int l = -1, r = -1;
    FOR(i, n) {
        if (n - idx + i >= n) break;
        if (s[i] == '1') {
            string tmp = s.substr(i, n - idx);
            string pos = XOR(s, tmp);
            if (res == "" || foo(pos, res)) {
                res = pos;
                l = i + 1, r = i + n - idx;
            }
        }
    }

    cout << "1 " << n << " " << l << " " << r << "\n";
}

int main() 
{ 
	fast_io
    
    int t; cin >> t;
    while (t--) {
        solve();
    }
	
	return 0; 
} 
