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
    int n,k,p,m; cin >>n>>k>>p>>m;
    vector<int> a(n);
    FOR(i,n) cin >>a[i];

    p--; // zero index

    if (k==n) {
        cout << floor(double(m)/a[p]) << "\n";
        return;
    }

    multiset<int> set; // FIRST K POS
    queue<pair<int,bool>> q;
    for (int i = 0; i < k; i++) set.insert(a[i]);
    for (int i = k; i < n; i++) {
        if (i == p) q.push({a[i],true});
        else q.push({a[i],false});
    }
    bool ok = p<k;
    int win = a[p];
    int res = 0;
    while (m>0) {
        if (ok && win > m) break;
        if (!ok && *(set.begin()) > m) break;
        if (ok) {
            res++;
            m -= win;
            set.erase(set.find(win));
            set.insert(q.front().ff);
            q.pop();
            q.push({win,true});
            ok = false;
        }
        else {
            auto it = set.begin();
            m -= *it;
            q.push({*it,false});
            set.erase(it);
            ok = q.front().ss;
            set.insert(q.front().ff);
            q.pop();
        }
    }
    cout << res << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
