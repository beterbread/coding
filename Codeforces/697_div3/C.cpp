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
    int a,b,k; cin >>a>>b>>k;
    vector<int> boy(k), girl(k);
    FOR(i,k) cin >>boy[i];
    FOR(i,k) cin >>girl[i];

    unordered_map<int,unordered_map<int,int,custom_hash>,custom_hash> buhao;
    vector<int> joe(a+1), mama(b+1);
    FOR(i,k) {
        buhao[boy[i]][girl[i]]++;
        joe[boy[i]]++;
        mama[girl[i]]++;
    }
    
    ll res = 0;
    int kk=k;
    FOR(i,kk) {
        int x=boy[i], y=girl[i];
        int bub = k-joe[x];
        int bub2 = mama[y]-buhao[x][y];
        res+=(bub-bub2);
        buhao[x][y]--;
        joe[x]--;
        mama[y]--;
        k--;
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
