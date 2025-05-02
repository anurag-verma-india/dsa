// Beats T 100, S 66
// https://leetcode.com/problems/search-in-rotated-sorted-array
// https://www.youtube.com/watch?v=6WNZQBHWQJs
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
    |      / |
    |    /   |
    |  /     |
    |/       |
    |        |    /
    |        |  /
    |________|/______
    ^      ^       ^
    |      |       |
    l      m       r
    The is the how a rotated sorted array will look

    use modified binary search
        modify the decision of picking the search space for the next iteration
          by the following method


        one of the halves will always be sorted in a rotated sorted array

        if left one is sorted (l =< m, consider the middle as being part of the left searchspace)
            check if the target element could exist in the left half
                (l <= target <=  m, in range of left and middle)
                if yes then pick this as search space for the next iteration
                    (r = m - 1)
            else
                we are sure that element can't be in the left search space so move check the right one for the next iteration
                    (l = m + 1)

        else right one is sorted (l > m)
            check if the target element could exist in the right half
                if yes then pick right search space for the next iteration
                else we become certain that it couldn't be in the right search space so we pick the left one instead

       if we come out of the loop then just return -1
       (now we are sure that the element is not in the array)
---
complexity
time:

space:

*/

class Solution {
   public:
    int search(vector<int>& A, int tar) {
        int l = 0, r = A.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (A[m] == tar) return m;

            else if (A[l] <= A[m]) {
                // left half is sorted
                if (A[l] <= tar && tar <= A[m]) {
                    // target is in this half
                    r = m - 1;
                } else {
                    // it is not in this half
                    l = m + 1;
                }
            } else {
                // right half is sorted
                if (A[m] <= tar && tar <= A[r]) {
                    // target is in this half
                    l = m + 1;
                } else {
                    // it's not
                    r = m - 1;
                }
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