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
    string a; cin >> a;
    map<char,char> map;
    int l = 0, r = n-1;
    int res = 0;
    vector<bool> joe(26,false);
    auto cost = [&](int start, int end) -> int {
        int cnt = 0;
        for (int i = start+1; i <= end; ++i) {
            if (joe[i]) {
                cnt++;
            }
            else {
                joe[i] = true;
            }
        }
        return end - start - cnt;
    };
    while (l < r) {
        if (map.find(a[l]) != map.end()) a[l] = map[a[l]];
        if (map.find(a[r]) != map.end()) a[r] = map[a[r]];
        int start = a[l]-'a', end = a[r]-'a';
        if (start > end) {
            swap(start,end);
        }
        if (start != end) {
            res += cost(start,end);
            map[a[r]] = a[l];
        }
        l++;
        r--;
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
