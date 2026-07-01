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
    vector<int> a(2*n);
    FOR(i,2*n) cin >> a[i];
    int res = 1; // 0 subarray = 1
    for (int mid = 1; mid < 2*n-1; mid++) {
        set<int> set;
        int l=-1, r=-1;
        if (a[mid]==a[mid+1]) { // 2 in center
            if (mid+2 >= 2*n) continue; 
            l=mid-1, r=mid+2;
        }
        else { // 1 in center
            l=mid-1, r=mid+1;
        }
        set.insert(a[mid]);
        while (l>=0 && r<2*n && a[l]==a[r]) {
            set.insert(a[l]);
            l--;
            r++;
        }
        // cout << l << ' ' << r << '\n';
        if (*set.begin()!=0) continue;
        int pos = 0;
        for (auto it = set.begin(); it != set.end(); it++) {
            if (next(it)==set.end()) {
                pos = *it+1;
            }
            if (*it+1 < *next(it)) {
                pos = *it+1;
                break;
            }
        }
        res = max(res,pos);
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
