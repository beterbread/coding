// Kadane's algorithm to find the maximum sum subarray

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int res = INT_MIN;
    int current = 0;
    for (int i : nums) {
        current += i;
        res = current > res ? current : res;
        if (current < 0) { // We don't carry negative prefixes
            current = 0;
        }
        // Essentially as long as it's positive, it will contribute to the maximum subarray
    }
    return res;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}