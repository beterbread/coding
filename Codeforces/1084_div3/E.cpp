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

pair<int,int> joe(int& x) {
    bool alice = true;
    int front = -1, back = -1;
    while (1) {
        bool ok = false;
        for (int j = 2; j <= sqrt(x); j++) {
            if (x % j == 0) {
                if (alice) {
                    if (back == -1) back = min(j,x/j);
                    x = max(j,x/j);
                }
                else {
                    if (front == -1) front = min(j,x/j);
                    x = max(j,x/j);
                }
                ok = true;
                break;
            }
        }
        if (!ok) break;
        alice = !alice;
    }
    return {front,back};
}

void solve() {
    int n; cin >>n;
    vector<int> a(n);
    FOR(i,n) cin >>a[i];

    bool ok = true;
    FOR(i,n-1) {;
        if (a[i]>a[i+1]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "Bob\n";
        return;
    }

    vector<int> res;
    FOR(i,n) {
        auto [front,back] = joe(a[i]);
        if ((front != -1 && front > a[i]) || (back != -1 && back < a[i])) {
            cout << "Alice\n";
            return;
        }
        if (front != -1) res.pb(front);
        res.pb(a[i]);
        if (back != -1) res.pb(back);
    }

    FOR(i,res.size()-1) {
        if (res[i]>res[i+1]) {
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
}

int main() 
{ 
	ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	int t; cin >> t;
    while (t--) solve();
	
	return 0; 
} 
