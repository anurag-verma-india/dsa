
// less efficient then looping and keeping a set
// t: 75ms - 17%, s: 94mb - 11%
// https://leetcode.com/problems/contains-duplicate/solutions/6075376/video-3-solutions-with-sorting-set-and-length/
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

---
complexity

space:

time:

*/
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uq(nums.begin(), nums.end());
        return uq.size() < nums.size();
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