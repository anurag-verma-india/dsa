// Not working
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*

Input:
    int arr: sorted rotated

Output:
    int: minimum element
    time complexity: O(log n)

Approach:

    Binary search

    Try to find an elemnet that satisfies this

    if arr[l] > arr[m] move right
    else move left
    since whichever of these two breaks the sequence the smallest will be found there

---
Complexity:

Time:

Space:
*/

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, m, min_e = INT_MAX;

        while (l <= r) {
            m = l + (r - l) / 2;

            if (nums[m] > nums[r]) {
                l = m + 1;
                min_e = min(min_e, nums[m]);
            } else {
                r = m - 1;
            }
        }
        return min_e;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();

    Solution sol;
    cout << "Min element: " << sol.findMin(int_vec) << "\n";
}