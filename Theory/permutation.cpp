#include <bits/stdc++.h>
using namespace std;

int main() {
    // next_permutation returns the next lexographically greater permutation 
    // if it doesn't exist, it returns false
    // vice versa for prev_permutation

    vector<int> a = {1,2,3};
    do {
        for (int& x: a) cout << x << " ";
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}