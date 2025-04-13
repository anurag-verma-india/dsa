// Beats T 100, M 48
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

    binary seach

    where the order breaks that's the smallest element
    (small, larger, largest or ascending order)

    compare mid elem w/ right if mid < right
    the order is correct which means smallest is not here
    move left
    otherwise move right
    continue

---
Complexity:

Time:

Space:
*/

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] < nums[r]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();

    Solution sol;
    cout << "Min element: " << sol.findMin(int_vec) << "\n";
}