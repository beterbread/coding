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
    vector<int> a(n);
    FOR(i,n) cin >>a[i];

    set<int> set;
    int mx = -1, mx2 = -1; // max and second greatest element
    FOR(i,n) {
        if (a[i]==n) mx = i;
        else if (a[i]==n-1) mx2 = i;
        if (mx!=-1 && mx2!=-1) break;
    }

    int l = min(mx,mx2), r = max(mx,mx2);
    for (int i = l+1; i <= r; i++) set.insert(a[i]);
    
    int res = (r-l>1 ? l + (n-r-1) : 0);
    while (r-l>1) {
        if (set.size() < 2) break;
        set.erase(a[l]);
        set.erase(a[r]);
        int ll = l, rr = r;
        int x = *prev(set.end()), y = *(prev(prev(set.end())));
        while (a[ll]!=x && a[ll]!=y) ll++;
        while (a[rr]!=x && a[rr]!=y) rr--;
        if (a[ll] > a[rr]) res += (ll-l-1);
        else res += (r-rr-1);
        l = ll;
        r = rr;
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
