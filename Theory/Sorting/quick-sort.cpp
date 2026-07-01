// Quick Sort, O(n*log(n))

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

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find the pivot element such that elements smaller than pivot
        // are on the left of the pivot and elements greater than pivot are on the right
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> nums = {1, 3, 8, 2, 9, 5, 6};
    quickSort(nums, 0, nums.size() - 1);
    for (int i : nums) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}