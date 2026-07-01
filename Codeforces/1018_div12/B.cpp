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
    ll n,k; cin >> n >> k;
    vector<ll> left(n),right(n);
    FOR(i,n) cin >> left[i];
    FOR(i,n) cin >> right[i];
    
    ll res = 0;
    FOR(i,n) {
        if (left[i]>right[i]) {
            res+=left[i];
            left[i]=0;
        }
        else {
            res+=right[i];
            right[i]=0;
        }
    }
    priority_queue<ll> pq;
    FOR(i,n) {
        if (left[i]==0) pq.push(right[i]);
        else pq.push(left[i]);
    }
    while (k>1) {
        res+=pq.top();
        pq.pop();
        k--;
    }
    cout << res+1 << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
