#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 4, 6, 9, 12, 23, 43, 56};

    // upper_bound = Finds the last position in which val could be inserted without changing the ordering.
    auto it = upper_bound(a.begin(), a.end(), 6);

    // lower bound = Finds the first position in which val could be inserted without changing the ordering.
    auto it2 = lower_bound(a.begin(), a.end(), 6);

    cout << *it << " " << *it2 << "\n";
}