// https://www.geeksforgeeks.org/dsa/longest-monotonically-increasing-subsequence-size-n-log-n/

#include <bits/stdc++.h>
using namespace std;

// Computes longest increasing subsequence in O(n*log(n))
int LIS(vector<int>& a) {
    int n = a.size();
    vector<int> res;
    res.push_back(a[0]); 
    for (int i = 1; i < n; i++) {
        if (a[i] > res.back()) {
            res.push_back(a[i]);
        }
        else {
            int low = lower_bound(res.begin(), res.end(), a[i]) - res.begin();
            res[low] = a[i];
        }
    }
    return res.size();
}

int main() {
    vector<int> a = {10, 22, 9, 33, 21, 50, 41, 60, 1};
    printf("Length of LIS is %d\n", LIS(a));

    // For longest decreasing subsequence (less common), multiply all elements by -1
    for (int i = 0; i < a.size(); i++) {
        a[i] = -a[i];
    }
    printf("Length of LDS is %d\n", LIS(a));

    return 0;
}