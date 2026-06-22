// t: 0ms, 100%; s: 17 mb, 41%;
#include <bits/stdc++.h>

#include "file_as_stdin.cpp"
#include "read_int.cpp"

/*

input:
    int[] nums

output:
    int[] ans: where nums[i] == ans[i] and ans[n + i] == nums[i]
    i.e. the ans array is 2 nums array concatenated

approach:
    make a new vector (ans) of size 2n
    for each element of nums place the element at i & n+i
    return ans
 */

class Solution {
   public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[n + i] = nums[i];
        }
        return ans;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> inp = read_int();

    Solution sol;
    vector<int> ans = sol.getConcatenation(inp);

    cout << "Input: ";
    for (auto ele : inp) cout << ele << " ";
    cout << endl;

    cout << "Output: ";
    for (auto ele : ans) cout << ele << " ";
    cout << endl;

    return 0;
}