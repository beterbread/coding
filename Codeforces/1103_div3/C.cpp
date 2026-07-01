#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        long long a,b,x; cin >> a >> b >> x;
        vector<long long> joe{a}, mama{b};
        while (1) {
            a = floor((long double)(a)/(long double)(x));
            joe.push_back(a);
            if (a == 0) break;
        }
        while (1) {
            b = floor((long double)(b)/(long double)(x));
            mama.push_back(b);
            if (b == 0) break;
        }
        long long res = INT_MAX;
        long long n = joe.size(), m = mama.size();
        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < m; ++j) {
                res = min(res,i+j+abs(joe[i]-mama[j]));
            }
        }
        cout << res << '\n';
    }
}
