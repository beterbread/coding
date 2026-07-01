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
	int n,x,y; cin >>n>>x>>y;
    vector<int> p(n);
    FOR(i,n) cin >>p[i];

    // rotate between portals to min element
    deque<int> dq;
    int mn = INT_MAX;
    for (int i = x; i < y; i++) {
        dq.pb(p[i]);
        mn = min(mn,p[i]);
    }
    while (dq.front() != mn) {
        dq.pb(dq.front());
        dq.pop_front();
    }

    deque<int> front, back;
    for (int i = 0; i < x; i++) {
        front.pb(p[i]);
    }
    for (int i = y; i < n; i++) {
        back.pb(p[i]);
    }
    if (!front.empty() && front.front() < mn) { // remove all but first
        while (front.size() != 1) {
            back.push_front(front.back());
            front.pop_back();
        }
    }
    if (!front.empty() && front.front() > mn) { // remove all 
        while (!front.empty()) {
            back.push_front(front.back());
            front.pop_back();
        }
    }
    while (!back.empty() && back.front() < mn) {
        front.pb(back.front());
        back.pop_front();
    }

    // result
    while (!front.empty()) {
        cout << front.front() << " ";
        front.pop_front();
    }
    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    while (!back.empty()) {
        cout << back.front() << " ";
        back.pop_front();
    }
    cout << "\n";
}

int main() 
{ 
	ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	int t; cin >> t;
    while (t--) solve();
	
	return 0; 
} 
