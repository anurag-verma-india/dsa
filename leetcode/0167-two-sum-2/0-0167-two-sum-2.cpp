
// Working but not accepted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

// Note: 1-indexed array

/*
For each index find the difference bw target and current

If the difference is greater than the current element
    Find the difference till the end
        If found return i indexed version of those indices

*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int diff;
        for (int i = 0; i < n; i++) {
            diff = target - numbers[i];
            if (diff >= numbers[i]) {
                // Could use find with iterators for this as well
                for (int j = i + 1; j < n; j++) {
                    if (numbers[j] == diff) return vector<int>({i + 1, j + 1});
                }
            }
        }
        return vector<int>(1, -1);  // Did not find the target
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();

    int target;
    cin >> target;

    Solution sol;

    vector<int> ans = sol.twoSum(int_vec, target);

    for (int num : ans) cout << num << " ";
    printf("\n");
}