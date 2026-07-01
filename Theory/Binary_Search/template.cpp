// Template for Binary Search problems 
// https://towardsdatascience.com/powerful-ultimate-binary-search-template-and-many-leetcode-problems-1f850ef95651

#include <bits/stdc++.h>
using namespace std;

// If we can discover some kind of monotonicity, 
// for example, if condition(k) is True then condition(k + 1) is True, 
// then we can consider binary search.

bool condition(int value) {
    // Design the condition function, most difficult part
}

// General template: Minimize k, such that condition(k) is True
int binarySearch(vector<int> nums) {
    // Correctly intialize the boundary variables
    // Set up the boundary to include ALL possible elements
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (condition(mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    // Decide return value, left or left - 1?
    // After exiting while loop, left is minimal k satisfying the condition function
    return left;
}