#include <bits/stdc++.h>
using namespace std;

// Efficiently calculate the value of x^n mod m
// Can be done in O(log(n)) time

int modpow(int x, int n, int m) {
    if (n == 0) return 1 % m;
    long long u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

// long long version
long long modpow(long long x, long long n, long long m) {
    long long result = 1;
    x = x % m; 
    while (n > 0) {
        if (n % 2 == 1) result = (result * x) % m;  
        x = (x * x) % m; 
        n /= 2;
    }
    return result;
}

int main() {
    int x = 3;
    int n = 13;
    int m = 100;

    int result = modpow(x, n, m);
    cout << x << "^" << n << " mod " << m << " = " << result << "\n";

    long long x2 = 123456789;
    long long n2 = 987654321;
    long long m2 = 1e9 + 7;

    long long result2 = modpow(x2, n2, m2);
    cout << x << "^" << n << " mod " << m << " = " << result2 << "\n";

    return 0;
}