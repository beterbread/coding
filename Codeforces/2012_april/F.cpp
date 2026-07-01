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
 
int rev(int x) {
    string xx = to_string(x);
    reverse(all(xx));
    return stoi(xx);
}
 
void solve() {
    int d; cin >>d;
    
    int n = 1e7;
    vector<bool> isPrime(n+1,true);
    isPrime[0]=false; isPrime[1]=false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i] && (ll)i*i<=n) {
            for (int j = i*i; j <= n; j+=i) {
                isPrime[j]=false;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i] && i!=rev(i) && isPrime[rev(i)]) {
            d--;
            if (!d) {
                cout << i << "\n";
                return;
            }
        }
    }
}
 
int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
 
    solve();
    
    return 0; 
} 