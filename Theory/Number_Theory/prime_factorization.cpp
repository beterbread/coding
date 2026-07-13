#include <bits/stdc++.h>
using namespace std;

// O(sqrt(n))
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

// Precompuite sieve: O(n*log(log(n))) Query: O(log(n))
// Sieve of Eratosthenes method
class PrimeFac {
public:
    const int n;
    vector<int> spf;
    PrimeFac(int n) : n(n), spf(n+1) {
        iota(spf.begin(),spf.end(),0);
        for (int i = 2; i * i <= n; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
    }

    vector<int> get_factors(int x) {
        vector<int> res;
        while (x > 1) {
            res.push_back(spf[x]);
            x /= spf[x];
        }
        return res;
    }
};