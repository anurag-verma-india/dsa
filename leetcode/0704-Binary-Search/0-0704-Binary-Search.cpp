// Time: beats 100%, Space: beats 45%
// https://leetcode.com/problems/binary-search/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*

Input:
    int arr: ascending order
    int: target to find in arr

Output:
    int: index of target var (or -1 if not found)

Approach:
    Binary search
    left = starting, right = n-1

    middle = left + (right - left)/2
    [because (right + left)/2 can cause int overflow for large enough numbers]

    if (middle < target) keep searching in the right portion
    else if (middle > target) keep searching in the left portion

    if (right < left) it means the element is not present in the array

---
Complexity:

Time: 
    O(log_2 n) [search domain size halves at each step]

Auxilary Space: 
    O(1) [No matter the size of the given array the variables used remains the same (4)]

*/

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1, m;

        while (l <= r) {
            m = l + (r - l) / 2;
            // m = (r + l) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    int target;
    cin >> target;

    // for (int n : int_vec) cout << n << " ";
    // cout << "\n";
    // cout << target << "\n";

    Solution sol;
    cout << "Target index: " << sol.search(int_vec, target) << "\n";
}