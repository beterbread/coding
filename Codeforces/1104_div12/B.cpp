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
    vector<int> a(n),b(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];
    vector<bool> used(n,false);
    int res = 0;
    FOR(i,n) {
        if (a[i] <= b[i] && !used[i]) {
            a[i] = b[i];
            used[i] = true;
            continue;
        }
        int joe = -1, mama = -1;
        for (int j = i-1; j >= 0; --j) {
            if (used[j]) continue;
            if (a[j] <= b[i]) {
                joe = j;
                break;
            }
        }
        for (int j = i+1; j < n; ++j) {
            if (used[j]) continue;
            if (a[j] <= b[i]) {
                mama = j;
                break;
            }
        }
        if (joe == -1 && mama == -1) {
            cout << "-1\n";
            return;
        }
        int mn = -1;
        if (joe == -1) {
            mn = mama;
        }
        else if (mama == -1) {
            mn = joe;
        }
        else {
            if (i-joe <= mama-i) mn = joe;
            else mn = mama;
        }
        used[i] = true;
        a[mn] = b[i];
        if (mn < i) {
            for (int j = mn; j < i; ++j) swap(a[j],a[j+1]);
        }
        else {
            for (int j = mn; j > i; --j) swap(a[j],a[j-1]);
        }
        res += abs(mn-i);
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
