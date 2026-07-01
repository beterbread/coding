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

vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n),b(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];

    int cnt = count(all(a),1);
    if (cnt>0) {
        cout << n-cnt << '\n';
        return;
    }
    // int g=a[0];
    // for (int i = 1; i < n; i++) g=gcd(g,a[i]);
    // cout << g << '\n';
    unordered_map<int,int> map; // lowest
    unordered_map<int,int> map2; // unique
    FOR(i,n) {
        int num = a[i];
        for (int x = 2; x * x <= num; x++) {
            if (num % x == 0) {
                int cnt=0;
                map2[x]++;
                while (num % x == 0) {
                    num /= x;
                    cnt++;
                }
                if (map.find(x)==map.end()) map[x]=cnt;
                else map[x]=min(map[x],cnt);
            }
        }
        if (num > 1) {
            map[num]=1;
            map2[num]++;
        }
    }
    int res = 0;
    FOR(i,n) {
        bool ok = false;
        int num = a[i];
        for (int x = 2; x * x <= num; x++) {
            if (num % x == 0) {
                if (map2[x]==1) ok = true;
                int cnt=0;
                while (num % x == 0) {
                    num /= x;
                    cnt++;
                }
                if (cnt>map[x]) ok = true;
            }
        }
        if (num > 1 && map2[num]==1) ok = true;
        if (ok) res++;
        cout << a[i] << " " << res << "\n";
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
