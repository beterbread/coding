#include <bits/stdc++.h>
using namespace std;

// Template to generate all permutations of a vector
vector<int> perm;
vector<bool> used;

void generate_permutations(const vector<int>& nums) {
    if (perm.size() == nums.size()) {
        for (int x : perm) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        perm.push_back(nums[i]);
        generate_permutations(nums);
        perm.pop_back();
        used[i] = false;
    }
}

// Example
int main() {
    vector<int> nums = {1, 2, 3};
    used.assign(nums.size(), false);
    generate_permutations(nums);
}
