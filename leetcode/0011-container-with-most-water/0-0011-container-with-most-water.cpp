// Solved (Self)
// https://leetcode.com/problems/container-with-most-water/description/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"
/*
Given:
    int array: height

Return:
    int: max container size (max area)

Approach:
    Using two pointers

    Go outward in
    For each pair
    calculate the area enclosed by the bars on the two pointers
    Then move the pointer at the shorter bar

    Keep track of the max area so far
---
Complexity
Time: 
    O(n) 
    The while loop would run at most n times 
    (if have have to compare all left elements with all right ones)

Space: 
    O(1)
    only auxilary memory is used in storing the max volume 
    which is an integer so it's constant space complexity
*/

class Solution {
   public:
    int maxArea(vector<int>& height) {
        // for (int n : height) printf("%d ", n);
        // printf("\n");
        int n = height.size();
        int j = 0, k = n - 1;
        if (n < 2) return 0;
        int maxV = 0;

        while (j < k) {
            int water_vol_2d = (k - j) * min(height[j], height[k]);
            maxV = max(maxV, water_vol_2d);
            if (height[j] < height[k]) {
                j++;
            } else {
                k--;
            }
        }

        return maxV;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    // for(int n:int_vec) printf("%d ", n);
    // printf("\n");

    Solution sol;
    cout << "\nContainer size: " << sol.maxArea(int_vec) << "\n";
}