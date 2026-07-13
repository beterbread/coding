#include <bits/stdc++.h>
using namespace std;

// nCr = number of ways to choose unordered sets of size r from a set of n distinct possibilities
// typically denoted as (n k)
// (n! / k! * (n - k)!) % m = n! * (k!)^-1 * ((n - k)!)^-1 % m

const int MAX_N = 1e6;
long long fac[MAX_N+1];
long long inv[MAX_N+1];

long long modexp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b) {
        if (b&1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void compute_fac(long long m) {
    fac[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) fac[i] = (fac[i-1] * i) % m;
}

// Fermat's Little Theorem a^-1 = a^m-2 % m
// (i!)^-1 * i = ((i - 1)!)^-1 
void compute_inv(long long m) {
    inv[MAX_N] = modexp(fac[MAX_N],m-2,m);
    for (int i = MAX_N; i >= 1; --i) inv[i-1] = (inv[i] * i) % m;
}

// n! * (k!)^-1 * ((n - k)!)^-1 % m
long long choose(long long n, long long r, long long m) {
    return fac[n] * inv[r] % m * inv[n-r] % m;
}