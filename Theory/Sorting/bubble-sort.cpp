// Bubble Sort, O(n^2) 

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (size_t i = 0; i < n; i++) { // n iterations
        // Swap every element that is greater than its next element
        for (size_t j = 0; j < n - 1; j++) { 
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
        // Greatest element will now be at the end
    }
}

int main() {
    vector<int> nums = {1, 3, 8, 2, 9, 5, 6};
    bubbleSort(nums);
    for (int i : nums) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}