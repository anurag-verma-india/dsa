

// https://www.youtube.com/watch?v=cQ1Oz4ckceM (neetcode)
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

// Note: 1-indexed array

/*
We know that the array is sorted

Let's use two pointers
Left = start index (0)
Right = ending index (n-1)

If sum is too big decrease right pointer
If sum is too small decrease left pointer
Keep going until pointers cross

*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right] ;
            if (sum == target)
                return vector<int>({left + 1, right + 1});  // 1 indexed
            else if (sum > target)
                right--;
            else
                left++;
        }
        return vector(1, -1);
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