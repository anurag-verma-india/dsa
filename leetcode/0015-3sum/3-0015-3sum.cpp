// Solved
// https://leetcode.com/problems/3sum/
// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0015-3sum.cpp
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*

Given:
    Integer array

Return:
    Integer array of all integer arrays (w/ Three elements), that add up to 0

Approach:
    Using two pointers
    (Actually three, but fixing one by looping through the array)

    sum = nums[i] + nums[j] + nums[k];
    i = looping index
    j = left pointer (i+1)
    k = right pointer (n-1)

    if sum < 0 -> (increase sum) move left pointer to right
    if sum > 0 -> (decrease sum) move right pointer to left
    otherwise sum == 0 -> add the triplet to the solution

    Skip the elements which are equal to one another
    If we reach the positive elements break the loop
    (Any elements after them can't add up to 0, will always be > 0)
---
Complexity
Time: O(nlog(n) + n^2) = O(n^2)
    Sorting (intosort)
    + for loop & inner while loop

Space: O(n + n) = O(n)

    Sorting (O(n) in worst case)
    + Result vector (O(n) [not O(n^3)] because unique triplets need to be found)
*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                    while (j < k && nums[k - 1] == nums[k]) {
                        k--;
                    }
                    k--;
                }
            }
        }
        return result;
    }
};
int main() {
    file_as_stdin("input.txt");
    // file_as_stdin("ip2.txt");
    vector<int> int_vec = read_int();

    Solution sol;
    vector<vector<int>> result = sol.threeSum(int_vec);

    for (auto v : result) printf("\n{%d, %d, %d}, ", v[0], v[1], v[2]);
    printf("\n");
}
