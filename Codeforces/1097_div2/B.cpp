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

    // solve 
    int MAXMAX = *max_element(all(a));
    multiset<int> set(all(a));
    vector<int> joe;
    int cur = -1;
    while (set.find(cur+1) != set.end()) {
        joe.pb(cur+1);
        set.erase(set.find(cur+1));
        cur++;
    }
    while (!set.empty()) {
        auto it = prev(set.end());
        joe.push_back(*it);
        set.erase(it);
    }

    // debug
    // cout << "MEX: " << cur+1 << '\n';
    // each(x,joe) cout << x << ' ';
    // cout << '\n';

    // calculate res
    int mx = 0;
    ll mx_sofar = 0;
    ll mex_sofar = 0;
    ll pos1 = 0;
    ll pos2 = 0;
    FOR(i,n) {
        ll pos3 = (mx_sofar + mex_sofar) + ll(n-i)*ll(MAXMAX);
        if (joe[i] <= cur) {
            if (MAXMAX == joe[i]) pos3 += joe[i]+1;
            else if (i>0) pos3 += joe[i-1]+1;
        }
        else {
            pos3 += cur+1;
        }
        pos2 = max(pos2,pos3);
        // pos1 
        mx = max(mx,joe[i]);
        pos1 += mx;
        mx_sofar += mx;
        if (joe[i] <= cur) {
            pos1 += joe[i]+1;
            mex_sofar += joe[i]+1;
        }
        else {
            pos1 += cur+1;
            mex_sofar += cur+1;
        }
    }
    cout << max(pos1,pos2) << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
