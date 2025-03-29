
// https://leetcode.com/problems/3sum/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Problem: Find set of all triplets that sum up to zero

Approach:
a + b + c = 0
b + c = a * -1

Now it's the two sum problem

For each element find the negative of that element, that is the target
Find all the elements that add up to that target

---
I think Time: O(n Log n + n^2) [sorting, searching for sum]
*/

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> nms;  // element, index
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            nms.push_back({nums[i], i});
        }
        sort(nms.begin(), nms.end());
        // for (auto n : nms) {
        //     cout << n.first << " --> " << n.second << "\n";
        // }

        for (int i = 0; i < n; i++) {
            int target = nms[i].first * -1;
            // cout << "target: " << target << "\n";

            int left = 0, right = n - 1;
            while (left < right) {
                // Skip i'th element
                if (left == i || right == i) continue;
                int sum = nms[left].first + nms[right].first;
                if (sum == target) {
                    ans.push_back(vector<int>({nms[i].second, nms[left].second, nms[right].second}));
                } else if (sum > target)
                    right--;
                else
                    left++;
            }
        }
        // If there are duplicates in the ans remove them
        return ans;

        // return vector<vector<int>>(1, vector<int>(1, -1));
        // return {};
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
