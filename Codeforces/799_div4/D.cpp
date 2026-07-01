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

int count(unordered_set<string>& st) {
    int res = 0;
    each(s, st) {
        string tmp = s;
        reverse(all(tmp));
        if (s == tmp) res++;
    }
    return res;
}

void solve() {
    string s; cin >> s;
    int x; cin >> x;

    unordered_set<string> st;
    st.insert(s);

    while (1) {
        int hr = stoi(s.substr(0, 2)), mn = stoi(s.substr(3, 2));
        int total = hr * 60 + mn;
        total += x;
        total %= 1440;
        mn = total % 60;
        hr = (total - mn) / 60;

        string s1 = to_string(hr), s2 = to_string(mn);
        s = (s1.length() == 1 ? "0" + s1 : s1) + ":" + (s2.length() == 1 ? "0" + s2 : s2);
        if (st.count(s) == 1) break;
        st.insert(s);
    }

    cout << count(st) << "\n";
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
