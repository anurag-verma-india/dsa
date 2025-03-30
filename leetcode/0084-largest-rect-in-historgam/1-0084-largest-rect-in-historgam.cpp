// Accepted but Not optimal (According to striver)
// https://leetcode.com/problems/largest-rectangle-in-histogram/
// https://www.youtube.com/watch?v=X0X6G-eWgQ8/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*

Area for each index = bar_height * (right_boundary - left_boundary + 1)
    [right_boundary[i] - (left_boundary[i] - 1)]
    We are including the right boundary in the width
    Subtracting the element left of the left boundary from the width
    (because we want to include the left boundary element in the width calculation)

Left boundary =  index of lefter element greater than or equal to current one in height
Right boundary =  index of righter element greater than or equal to current one in height

Calculate left boundary
(left most element index with greater or equal height to each one)
[The stack will have increasing order from bottom to top in both cases]

Keep a stack if it's empty add current element to the stack

if the top element is greater than or equal to the current one, pop
(because that is not the left boundary the boundary can be extended further)
if the element at top is smaller than the current one (hole)
    left boundary for current idx is that index + 1

Similarly calculate the right boundary
Start from right this time
if the element at the top is greater than or equal to current, pop
(because the boundary can be extended further)
if the element is smaller than current (that's a hole)
    right_boundary[current_index] = top - 1

*/

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        // For storing indexes
        int n = heights.size();
        stack<int> st;
        vector<int> left_boundary(n);
        vector<int> right_boundary(n);

        // Calculating left boundary
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty())
                left_boundary[i] = 0;
            else
                left_boundary[i] = st.top() + 1;
            st.push(i);
        }

        // Reusing stack
        while (!st.empty()) st.pop();

        // Calculating right boundary
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty())
                right_boundary[i] = n - 1;
            else
                right_boundary[i] = st.top() - 1;
            st.push(i);
        }
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            maxA = max(maxA, (int)(right_boundary[i] - left_boundary[i] + 1) * heights[i]);
        }
        return maxA;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    Solution sol;
    cout << "Greatest area is " << sol.largestRectangleArea(int_vec) << "\n";
}