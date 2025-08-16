// t: 16ms - 96%, s: 71mb - 89%
// https://leetcode.com/problems/contains-duplicate/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:

input:
    int[] nums

output:
    bool ans: the array contains duplicates

approach:
    sort the list
    iterate through the list and if any adjacent elements are equal return true (contains duplicate)

    At the end return false

---
complexity

space:

time:

*/

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();

    Solution sol;

    string ans = sol.containsDuplicate(int_vec) ? "true" : "false";

    cout << "Contains duplicate: " << ans << endl;

    return 0;
}