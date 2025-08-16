
// t: 92ms - 15%, s: 93mb - 24%
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
    keep a set of all elements

    traverse list one by one
    check if this values exists in the set: return true
    otherwise: add the value to the set

    if the list is over and no duplicates were found  return false by default

---
complexity

space:

time:

*/

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> uq;

        for (int n : nums) {
            if (uq.count(n)) {
                return true;
            } else {
                uq.insert(n);
            }
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