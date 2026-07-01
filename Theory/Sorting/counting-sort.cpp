// Counting Sort, O(n) 

#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr, int k, int n) {
    int count[k]; // Bookkeeping array
    for (int i = 0; i < k; i++) {
        count[i] = 0;
    }

    // Construct bookkeeping array, will represent indices
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i < k; i++) { // Sum for indices
        count[i] = count[i - 1] + count[i];
    }
    
    // Construct result and copy it to original array
    int res[n];
    for (int i = n - 1; i >= 0; i--) {
        res[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = res[i];
    }
}

int main() {
    int n = 4, k = 7;
    vector<int> arr = { 5, 6, 5, 2}; 
    countingSort(arr, k, n);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}