#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenesm O(n * log(log(n))
// For finding all primes in a range

int main() {
    int n = 1000000; 
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return 0;
}