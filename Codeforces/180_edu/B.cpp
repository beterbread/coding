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
        int n; cin >>n;
        vector<int> a(n);
        FOR(i,n) cin >>a[i];

        for (int i = 0; i<n-1; i++) {
            if (abs(a[i]-a[i+1])<=1) {
                cout << "0\n";
                return;
            }
        }
        for (int i = 0; i<n-1; i++) {
            if (i>0 && i+1<n) {
                int low = min(a[i-1],a[i])-1, high = max(a[i-1],a[i])+1;
                if (a[i+1]>=low && a[i+1]<=high) {
                    cout << "1\n";
                    return;
                }
                low = min(a[i+1],a[i])-1, high = max(a[i+1],a[i])+1;
                if (a[i-1]>=low && a[i-1]<=high) {
                    cout << "1\n";
                    return;
                }
            }
        }
        cout << "-1\n";
    }

    int main() 
    { 
        ios::sync_with_stdio(false); 
        cin.tie(nullptr);

        int t; cin >> t;
        while (t--) solve();
        
        return 0; 
    } 
