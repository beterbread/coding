#include <bits/stdc++.h>
using namespace std;

// Template to generate all subsets of a vector
vector<vector<int>> subsets;
vector<int> subset;

void generate_subsets(int i, const vector<int>& nums) {
    if (i == (int)nums.size()) {
        subsets.push_back(subset);
        return;
    }
    generate_subsets(i + 1, nums);
    subset.push_back(nums[i]);
    generate_subsets(i + 1, nums);
    subset.pop_back();
}

// Example
int main() {
    vector<int> nums = {1, 2, 3};
    generate_subsets(0, nums);

    for (const auto& s : subsets) {
        for (int x : s) cout << x << " ";
        cout << "\n";
    }
}