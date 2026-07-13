#include <bits/stdc++.h>
using namespace std;

// O(log(n))
long long modexp(long long x, long long n, long long m) {
    x %= m;
    long long res = 1;
    while (n) {
        if (n&1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}
