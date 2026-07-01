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

    vector<vector<int>> ops;
    priority_queue<int,vector<int>,greater<int>> pq1(all(a)),pq2(all(b));
    FOR(i,n) {
        int want1=pq1.top(); pq1.pop();
        int want2=pq2.top(); pq2.pop();
        for (int j = i+1; j<n; j++) {
            if (a[j]==want1 && b[j]==want2) {
                ops.pb({i,j});
                swap(a[i],a[j]);
                swap(b[i],b[j]);
                break;
            }
        }
    }
    FOR(i,n-1) {
        if (a[i]>a[i+1] || b[i]>b[i+1]) {
            cout << "-1\n";
            return;
        }
    }
    cout << ops.size() << '\n';
    each(x,ops) {
        cout << x[0]+1 << " " << x[1]+1 << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
