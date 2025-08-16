
// t: 44ms - 74%, s: 91mb - 48%
// https://leetcode.com/problems/contains-duplicate/solutions/3672475/4-method-s-c-java-python-beginner-friendly/
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
        unordered_set<int> uq;

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