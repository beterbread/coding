// Insertion Sort, O(n^2) 

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& nums) {
    int n = nums.size();
    for (size_t i = 1; i < n; i++) {
        int temp = nums[i];
        int j = i - 1;
        // Shift all elements greater than temp to the right
        while (j >= 0 && nums[j] > temp) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
}

int main() {
    vector<int> nums = {1, 3, 8, 2, 9, 5, 6};
    insertionSort(nums);
    for (int i : nums) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}