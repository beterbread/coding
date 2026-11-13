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
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    priority_queue<int> odd, even;
    FOR(i,n) {
        if (i&1) odd.push(a[i]);
        else even.push(a[i]);
    }
    bool joe = odd.top() > even.top();
    int prev1 = joe ? odd.top() : even.top();
    int prev2 = INT_MAX;
    if (joe) odd.pop();
    else even.pop();
    bool tog = joe;
    while (odd.size() || even.size()) {
        if (tog) { // take from even
            if (even.size() == 1) {
                int x = even.top(); even.pop();
                if (x > prev1 || x > prev2) {
                    cout << "NO\n";
                    return;
                }
            }
            else {
                int x = even.top(); even.pop();
                int y = even.top(); even.pop();
                if ((x > prev1 || y > prev2) && (y > prev1 || x > prev2)) {
                    cout << "NO\n";
                    return;
                }
                prev1 = min(prev1,x);
                prev2 = min(prev2,y);
            }
        }
        else {
            if (odd.size() == 1) {
                int x = odd.top(); odd.pop();
                if (x > prev1 || x > prev2) {
                    cout << "NO\n";
                    return;
                }
            }
            else {
                int x = odd.top(); odd.pop();
                int y = odd.top(); odd.pop();
                if ((x > prev1 || y > prev2) && (y > prev1 || x > prev2)) {
                    cout << "NO\n";
                    return;
                }
                prev1 = min(prev1,x);
                prev2 = min(prev2,y);
            }
        }
        tog = !tog;
    }
    cout << "YES\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
