// Beats T 100, M 79
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// https://www.youtube.com/watch?v=F9c7LpRZWVQ
// #include <bits/stdc++.h>
#include <climits>
#include <iostream>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*

input
    int arr1: sorted array
    int arr2: sorted array

output
    double: median of the combined arrays

approach
    Binary search will be on the basis of symmetry

    left half     |     right half
                    mid1
               l1 | r1
            a b c | d e f
          s t u v | w x y z
               l2 | r2
                    mid2

        n1 + n2 is even
            median = [min(l1, l2) + max(r1, r2)] / 2
        n1 + n2 is odd
        [left half = (n1 + n2 + 1)/2, i.e. 1 extra element on the left]
            median = min(l1, l2)

    How many elements from arr1 (shorter array)
    How many elements from the arr1 will be on the left and how many on the right
    To determine if the symmetry is valid, compare the cross elements

    l1 | r1
    l2 | r2

    l1 < r2 && l2  < r1 return the median

    If l1 > r2
        go left (i.e. pick more less elements from arr1)
        [it means, arr1 has elements on the left that are greater than l1]
        [Make l1 smaller]
    else if l2 > r1
        go right
        [Make r1 smaller, in other words l2 greater]

---
complexity:
time

space

*/

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        if (n1 > n2) return findMedianSortedArrays(arr2, arr1);  // Make sure smaller array is arr1

        // cout << "Array 1: ";
        // for (int a : arr1) cout << a << ", ";
        // cout << "\n";
        // cout << "Array 2: ";
        // for (int a : arr2) cout << a << ", ";
        // cout << "\n";

        int n = n1 + n2;
        int left = (n1 + n2 + 1) >> 1;
        // int left = (n1 + n2 + 1) / 2;
        // int left;
        // // Both of these conditions will have the same result as the odd one
        // if ((n1 + n2) / 2 == 1) {
        //     // odd
        //     left = (n1 + n2 + 1) / 2;
        // } else {
        //     // even
        //     left = (n1 + n2) / 2;
        // }

        int low = 0, high = n1;

        while (low <= high) {
            int m1 = (low + high) / 2;
            // int m1 = (low + (high - low)) >> 1;  // bit shift right to 1, same as division by 2 (more efficient)
            int m2 = left - m1;
            // int m1 = low + (high - low) / 2;
            // int m1 = (low + high) / 2;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (m1 - 1 >= 0) l1 = arr1[m1 - 1];
            if (m2 - 1 >= 0) l2 = arr2[m2 - 1];
            if (m1 < n1) r1 = arr1[m1];
            if (m2 < n2) r2 = arr2[m2];
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 != 0) {
                    // odd
                    return (double)max(l1, l2);
                } else
                    return ((double)((max(l1, l2) + min(r1, r2)) / 2.0));
                // return (double)((max(l1, l2) + min(r1, r2)) / 2);
            } else if (l1 > r2) {
                // move left (find a smaller l1)
                high = m1 - 1;
            } else {
                low = m1 + 1;
            }
        }
        return 0;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec1 = read_int();
    vector<int> int_vec2 = read_int();

    Solution sol;
    double median = sol.findMedianSortedArrays(int_vec1, int_vec2);

    cout << "Median is " << median << "\n";
}