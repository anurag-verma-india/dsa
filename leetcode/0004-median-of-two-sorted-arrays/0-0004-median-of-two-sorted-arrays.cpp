// Approach not clear
// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*

input 
    int arr1: sorted array
    int arr2: sorted array

output 
    double: median of the combined arrays

approach 
    add the lengths of the two arrays

    then determine the middle value that would be if there was an array of that size 

    if no. of val even
        md1 = {(m + n) / 2} th value
        md1 = {[(m + n) / 2] + 1 } th value
        median = (md1 + md2) / 2 
    if num of val odd
        median = {[( m + n ) / 2] + 1} th value

    
    handling odd case because it's easier for now 

    the median value will be the middle one when we merge the two arrays

    so it's index will be the one we found in the previous step

    so we just need to find the index that the combined array will have
    the sum of the indices of them will be m1 + m2 + 1 == median_pos


    start checking from the 


    p = index in first array
    k = index in second array

    for each p + k + 1 == median_pos && b[k-1] < a[p] < b[k]
        then b[k] is the median

    first assume that median is in the second array
        then we vary our k and calculate then check our p th element accordingly (median - k - 1)

        0   0   = 0 + 0 + 1
        2 , 3 1 
        median idx = ( 3 / 2 )  = 1 
        median idx = ( sum of sizes / 2 ) th index

        median_idx == p + k
        for the above array
            k = 1 
            p = median_idx - k - 1
              = 1 - 1
        
        0 1  0 1 2
        1 2, 3 4 5 
        median_idx = 5/2 = 2
        ##// median == p + k + 1
        k = 1
        p = 2 - 1 - 1
          = 1


        

        
    then assume median is in the first array

---
complexity: 
time 

space 

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
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