// Not working
// Cannot figure out all the edge cases
// https://leetcode.com/problems/search-in-rotated-sorted-array

#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
input:
    int arr: sorted rotated array
    int: target number

output:
    int: index of target number or -1 for not found

approach:
    find k first
    k is the index of smallest element

        smaller < larger < largest
        find the break in this order

            left, right for range

                if mid < right
                    correct order, no break here
                    move left
                else move right
                keep min in this process
---
complexity
time:

space:

*/

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, m;
        int k = 0;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (l == r) {
                k = l;
                break;
            } else if (nums[m] < nums[r]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        l = 0, r = n - 1;
        int lt = (l + k) % n, rt = (r + k) % n;

        // while (l <= r || (lt + k) % n < (rt + k) % n) {
        // while (l <= r) {
        while ((lt - k + n) % n <= (rt - k + n) % n) {
            // "Translating" the left and right pointers for this k rotated array
            // int lt = (l + k) % n, rt = (r + k) % n;
            lt = (l + k) % n, rt = (r + k) % n;

            m = lt + (rt - lt) / 2;  // Apparently this does not work
            // m = (rt + lt) / 2;  // Brute forcing through intuitions is not good
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    int target;
    cin >> target;

    Solution sol;

    int ans = sol.search(int_vec, target);
    cout << "Element found at " << ans << "\n";
    return 0;
}