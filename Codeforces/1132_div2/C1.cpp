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

vector<bool> sieve(200001,true);
vector<int> nextPrime(200001,-1);

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    each(x,a) {
        if (nextPrime[x] != -1 && abs(nextPrime[x] - x) <= x) {
            x = nextPrime[x];
        }
        cout << x << ' ';
    }
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= 200000; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= 200000; j += i) {
                sieve[j] = false;
            }
        }
    }
    int next = -1;
    for (int i = 200000; i >= 2; --i) {
        nextPrime[i] = next;
        if (sieve[i]) next = i;
    }
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
