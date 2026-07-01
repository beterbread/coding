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

void solve() {
    string s; cin >> s;
    string t; cin >> t;

    vector<int> freq(26, 0);
    each(c, s) freq[c - 'a']++;
    each(c, t) freq[c - 'a']--;

    // construct order of s 
    vector<string> a(26, "");
    string curr = "";
    each(c, s) {
        if (curr.length() > 0 && curr[0] < c) {
            a[curr[0] - 'a'] = curr;
            curr = "";
        }
        curr.pb(c);
    }
    a[curr[0] - 'a'] = curr;

    // each(str, a) cout << (str != "" ? str + " " : "");
    // cout << endl;

    // each(x, freq) cout << x << " ";
    // cout << endl;

    // if any freq > 0, 불가능
    string res = "";
    FOR(i, 26) {
        if (freq[i] > 0) {
            cout << "Impossible\n";
            return;
        }
        string pos1 = a[i], pos2 = "";
        FOR(j, abs(freq[i])) {
            pos1.pb(i + 'a');
            pos2.pb(i + 'a');
        }
        pos2 += a[i];
        res = pos1 < pos2 ? res + pos1 : res + pos2;
    }
    
    cout << res << "\n";
}

int main() 
{ 
	fast_io

	int t;
    cin >> t;
    while (t--) {
        solve();
    }
	
	return 0; 
} 
