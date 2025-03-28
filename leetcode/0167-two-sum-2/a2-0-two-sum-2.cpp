
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Given:
    int arr: numbers (sorted in non desc. order)
    int target: target element

Return:
    1-indexed indices of two elements that add up to the target
    (From the input element)

Approach:
    Use two pointers (use the fact that array is in ascending order)

    One left pointer (starts from the 0th element)
    One right pointer (starts from the n-1th, i.e. last element)

    Calculate the sum of the elements on the left and right pointer
    If sum is greater -> move right pointer to the left
    (because that will make the sum smaller, as the array is sorted)

    If the sum is smaller -> Move left pointer to the right
    (that will make the sum greater; because non decreasing order of elements)
*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), left = 0, right = n - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
                return {left + 1, right + 1};
        }
        return {-1, -1};
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