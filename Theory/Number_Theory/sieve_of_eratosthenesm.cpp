#include <bits/stdc++.h>
using namespace std;

// O(n * log(log(n))
int main() {
    int n = 1000000; 
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
}
