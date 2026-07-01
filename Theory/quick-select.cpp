// Quick select algorithm to find kth smallest element
// Time complexity O(n*log(n))

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment the index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot element in the correct position
    return i + 1;
}

int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low]; // Only one element
    }

    int pivot = partition(arr, low, high); // Partitioning index

    // The pivot is in its final sorted position
    if (k == pivot) {
        return arr[pivot];
    } else if (k < pivot) {
        return quickSelect(arr, low, pivot - 1, k); // Search in the left partition
    } else {
        return quickSelect(arr, pivot + 1, high, k); // Search in the right partition
    }
}

int main() {
    vector<int> nums = {1, 3, 8, 2, 9, 5, 6};
    cout << quickSelect(nums, 0, nums.size() - 1, 0) << endl;
    return 0;
}