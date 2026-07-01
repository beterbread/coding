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
    ll x; cin >>x;

    int sum = 0, sum2 = 0;
    vector<int> digits, digits2;
    while (x) {
        digits.pb(x%10);
        digits2.pb(x%10);
        x/=10;
        sum+=digits.back();
        sum2+=digits2.back();
    }

    int pos1 = 0;
    while(sum>=10) {
        int mx = 0, idx = 0;
        for (int i = 0; i < digits.size()-1; i++) {
            if (digits[i]>mx) {
                mx=digits[i];
                idx=i;
            }
        }
        pos1++;
        sum-=mx;
        digits[idx]=0;
    }

    int pos2 = 0;
    if (digits2.back()>1) {
        sum2-=(digits2.back()-1);
        pos2++;
    }
    while(sum2>=10) {
        int mx = 0, idx = 0;
        for (int i = 0; i < digits2.size()-1; i++) {
            if (digits2[i]>mx) {
                mx=digits2[i];
                idx=i;
            }
        }
        pos2++;
        sum2-=mx;
        digits2[idx]=0;
    }

    cout << min(pos1,pos2) << "\n";
}

int main() 
{ 
	ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	int t; cin >> t;
    while (t--) solve();
	
	return 0; 
} 
