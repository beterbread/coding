#include <bits/stdc++.h>
using namespace std;

// O(log(a))
// std has a gcd function, this is just for theory

long long gcd1(long long a, long long b) {
    return b == 0 ? a : gcd1(b,a%b);
}

// Cool iterative version
long long gcd2(long long a, long long b) {
    while (b) {
        long long R = a%b;
        a = b;
        b = R;
    }
    return a;
}

// a * b = gcd(a,b) * lcm(a,b)
