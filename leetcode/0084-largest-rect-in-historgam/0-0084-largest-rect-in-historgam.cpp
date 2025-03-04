// Not accepted
// Working, but not for large inputs (30000 elements)
// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"
/*
Given:
    Array of numbers representing height of bars in an histogram (in units)
    Width of each bar is 1 unit

To find:
    The area of the largest rectangle

Approach:
    Start with 1 bar at a time and the starting element
    Calculate area and if the area is greater then prev_greatest change it
    Take 2 bars and continue like this
*/

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int la = 0;  // (largest area)
        /*
        Start len = 1 to n
        for each length check area of that much concurrent bars
        (smallest from these concurrent ones is the height)
        If the area of any of these is greater then largest area (la) replace that
        */
        // if (n == 1) la = heights[0];
        for (int l = 1; l <= n; l++) {
            for (int st = 0; st <= n - l; st++) {
                // i = starting element for this length
                // up to l elements before end
                int smallest = heights[st];

                // Finding the height of the smallest bar
                for (int j = st; j < st + l; j++)
                    // Checking each element in this run
                    // If this works change this brute force to find smallest
                    if (smallest > heights[j]) smallest = heights[j];

                int curr_area = smallest * l;
                if (la < curr_area) la = curr_area;
            }
        }
        return la;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    Solution sol;
    cout << "Greatest area is " << sol.largestRectangleArea(int_vec) << "\n";
}