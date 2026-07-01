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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
	int n; cin >>n;
    unordered_set<int,custom_hash> users;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    FORD(i,n) {
        int l; cin >>l;
        vector<int> tmp(l);
        FORD(i,l) cin >>tmp[i];

        vector<int> tmp2;
        unordered_set<int,custom_hash> dup;
        FOR(i,l) {
            if (dup.count(tmp[i])) continue;
            tmp2.pb(tmp[i]);
            dup.insert(tmp[i]);
            users.insert(tmp[i]);
        }
        pq.push(tmp2);
    }

    vector<int> res;
    unordered_set<int,custom_hash> seen;
    while (seen.size() != users.size()) {
        auto x = pq.top(); pq.pop();
        each(y,x) {
            res.pb(y);
            seen.insert(y);
        }

        // remove seen
        vector<vector<int>> next;
        while (!pq.empty()) {
            auto x = pq.top(); pq.pop();
            vector<int> tmp;
            each(y,x) {
                if (seen.count(y)) continue;
                tmp.pb(y);
            }
            next.pb(tmp);
        }
        each(x,next) pq.push(x);
    }

    each(x,res) cout << x << " ";
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
