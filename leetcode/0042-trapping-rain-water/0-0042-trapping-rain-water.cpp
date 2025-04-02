// Beats 100% not checked if optimal or not
// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Input:
    int arr: height of bars

Output:
    int: units of rainwater trapped

Approach:
    For each bar calculate two arrays
    bar left & right to it which are higher than it (high_left, high_right)

    for each bar
        add get height of left and right higher bar (whichever one is lower)
        Subtract current bar's height
        Add that number to the result (rainwater trapped)

    # For calculating height of left & right higher bars

    For left higher ones
    Go from left to right
    Save max bar thus far (initialize by 0)
    high_left = max bar thus far

    Do the same for right ones (starting from right bar)
---
Complexity

Time:

Space:
*/

class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size(), result = 0;  // result is amount of trapped water
        vector<int> high_left(n), high_right(n);

        int max_bar = 0;
        for (int i = n - 1; i >= 0; i--) {
            max_bar = max(max_bar, height[i]);
            high_right[i] = max_bar;
        }
        max_bar = 0;
        for (int i = 0; i < n; i++) {
            max_bar = max(max_bar, height[i]);
            high_left[i] = max_bar;
            result += min(high_left[i], high_right[i]) - height[i];
        }
        return result;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    for (int n : int_vec) cout << n << " ";
    cout << "\n";
    Solution sol;
    cout << "Trapped Rainwater: " << sol.trap(int_vec);
    printf("\n");
    return 0;
}