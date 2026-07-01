// Selection Sort, O(n^2) 

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& nums) {
    int n = nums.size();
    for (size_t i = 0; i < n - 1; i++) {
        int min = i; // Hold first element index
        // Get min in rest of the array
        for (size_t j = i + 1; j < n; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        // Swap first element with minimum element in rest of the array
        swap(nums[i], nums[min]);
    }
}

int main() {
    vector<int> nums = {1, 3, 8, 2, 9, 5, 6};
    selectionSort(nums);
    for (int i : nums) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}