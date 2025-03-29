// Not working, not implemented perfectly
// https://www.youtube.com/watch?v=jzZsG8n2R9A&pp=ygUNbGVldGNvZGUgM3N1bQ%3D%3D
// https://leetcode.com/problems/3sum/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*

Given:
    Integer array

Return:
    Integer array of all integer arrays (w/ Three elements), that add up to 0

Problem: Find set of all triplets that sum up to zero

Approach:
    a + b + c = 0
    a + b  = -c
    -1 * (a + b) = c

    (target = c)
    (sum = a + b)
    target = -1 * sum

    Solving using two pointers
    Sorting the array
    Then iterating through all elements in the array

    For each element picking a left pointer (0) & right pointer (n-1)
    Calculating sum of the elements on two pointers
    If sum > target (current element) -> move right pointer 1 element left (i.e. decrease sum)
    If sum < target -> move left pointer 1 place to right (i.e. increase sum)
    if sum == target -> add left pt, right pt, curr element triplet to the ans array

    Also skip the elements if left or right pointers equal to current array element

---
Complexity
*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // for(auto n: nums) cout << n << " ";
        // printf("\n");
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left < right) {
                if (left == i) {
                    left++;
                    continue;
                }
                if (right == i) {
                    right--;
                    continue;
                }
                int sum = (nums[left] + nums[right]) * -1;

                if (sum < nums[i]) {
                    left++;
                    continue;
                } else if (sum > nums[i]) {
                    right--;
                    continue;
                } else
                    ans.push_back({nums[i], nums[left], nums[right]});
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
