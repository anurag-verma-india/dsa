// I don't remember from where but I definitely looked it up somewhere
// https://leetcode.com/problems/3sum/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Problem: Find set of all triplets that sum up to zero

Approach:
We don't care about indexes we just want to return the numbers
So, sort the numbers

Take three pointers
Fix one pointers on each element consecutively
For each one of them
Fix the other two on start or end (which does not cover the first one)

If the sum is bigger than the fixed number
Move the right pointer one position to the left
If the sum is smaller move the left pointer one position to the right

If the sum is equal then add the triplet to the solution
Keep going till the right pointer is bigger than the left one

---
Complexity
*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            // Fixed pointer is i
            int right = n - 1, left = 0;
            while (right > left && left >= 0 && right < n) {
                if (left == i) {
                    left++;
                    continue;
                }
                if (right == i) {
                    right--;
                    continue;
                }
                cout << "left: " << left << " ";
                cout << "right: " << right << " ";
                cout << "i: " << i << "\n";
                int sum = nums[left] + nums[right];
                if (sum == nums[i]) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    right = n - 1, left = 0;
                    continue;
                } else if (sum > nums[i])
                    right--;
                else if (sum < nums[i])
                    left++;
            }
        }
        return ans;
    }
};
int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();

    Solution sol;
    vector<vector<int>> ans = sol.threeSum(int_vec);

    for (auto v : ans) printf("\n{%d, %d, %d}, ", v[0], v[1], v[2]);
    printf("\n");
}
