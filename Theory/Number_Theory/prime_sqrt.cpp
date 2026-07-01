#include <bits/stdc++.h>
using namespace std;

// If a number n is not prime, it can be represented
// as a product a * b, where a <= sqrt(n) or b <= sqrt(n),
// so it certainly has a factor between 2 and floor(sqrt(n)).

// Using this observation, we can both test if a number is a prime 
// and find the prime factorization of a number in O(sqrt(n)) time.

bool prime(int n) {
    if (n < 2) return false;
    for (int x = 2; x * x <= n; x++) {
        if (n % x == 0) return false;
    }
    return true;
}

// The function factors constructs a vector that 
// contains the prime factorization of n.
// The function divides n by its prime factors,
// and adds them to the vector.
// If n > 1, it is prime and the last factor.

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

int main() {
    int n = 84;  

    cout << "Number: " << n << "\n";
    cout << "Is prime? " << (prime(n) ? "Yes" : "No") << "\n";

    vector<int> f = factors(n);
    cout << "Prime factors: ";
    for (int x : f) cout << x << " ";
    cout << "\n";

    return 0;
}