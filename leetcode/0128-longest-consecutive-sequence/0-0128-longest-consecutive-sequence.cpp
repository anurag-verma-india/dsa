
// https://leetcode.com/problems/longest-consecutive-sequence
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time

input:
    int arr: nums

output:
    int: n
    longest consecutive characters

approach:
    global_max = 0
    for each element
        Remove elements from array if they've already been counted for some max

        loop through the array by while loop
        while: not reached end
            try to find next consecutive element for current
            (search from current +1 to end)
            if found
                increase counter
                if found element is at later index remove it
            remove any occurrence of curr ele later in arr (arr.begin() + i + 1, arr.end())
            keep track of max_count
---
complexity

space:

time:

*/

// Working with TLE
class Solution {
   public:
    int longestConsecutive(vector<int>& na) {
        int i = 0, max_yet = 0;
        while (i < (int)na.size()) {
            int count = 1;
            int ele = na[i];
            vector<int>::iterator nxt;
            vector<int>::iterator prev = find(na.begin(), na.end(), ele - 1);  // Check later in the array
            bool flag = true;
            if (prev != na.end()) {
                // if (prev != na.end() && prev > na.begin() + i) {
                // A smaller element then this exists later in the array
                flag = false;
            }
            while (flag) {
                flag = false;  // Assume next element is not found
                nxt = find(na.begin(), na.end(), ele + 1);
                prev = find(na.begin(), na.end(), ele - 1);
                if (nxt != na.end()) {
                    // prev = find(nu.begin(), nu.end(), ele - 1);
                    // if (nxt != nu.end() && (prev == nu.end() || prev < nu.begin() + i)) {
                    // Update flag to show that
                    // element is found
                    // & there is no element smaller then this later in the array
                    flag = true;
                    if (nxt > na.begin() + i) {
                        na.erase(nxt);
                    }
                    count++;
                    ele++;
                }
            }
            max_yet = max(max_yet, count);
            i++;
        }
        return max_yet;
    }
};

// class Solution {
//    public:
//     int longestConsecutive(vector<int>& nu) {
//         int i = 0, max_yet = 0;
//         while (i < (int)nu.size()) {
//             int count = 1;
//             int ele = nu[i];
//             vector<int>::iterator nxt;
//             vector<int>::iterator prev = find(nu.begin(), nu.end(), ele - 1);
//             bool flag = true;
//             if (prev != nu.end() && prev > nu.begin() + i) {
//                 // A smaller element then this exists later in the array
//                 flag = false;
//             }
//             while (flag) {
//                 flag = false;  // Assume next element is not found
//                 nxt = find(nu.begin(), nu.end(), ele + 1);
//                 prev = find(nu.begin(), nu.end(), ele - 1);
//                 if (nxt != nu.end()) {
//                 // prev = find(nu.begin(), nu.end(), ele - 1);
//                 // if (nxt != nu.end() && (prev == nu.end() || prev < nu.begin() + i)) {
//                     // Update flag to show that
//                     // element is found
//                     // & there is no element smaller then this later in the array
//                     flag = true;
//                     if (nxt > nu.begin() + i) {
//                         nu.erase(nxt);
//                     }
//                     count++;
//                     ele++;
//                 }
//             }
//             max_yet = max(max_yet, count);
//             i++;
//         }
//         return max_yet;
//     }
// };

// class Solution {
//    public:
//     int longestConsecutive(vector<int>& nu) {
//         // int n = nu.size();
//         // if (nu.size() <= 0) return 0;
//         // for (int i = 0; i < n; i++) {
//         int global_max = 0;
//         int i = 0;
//         // while (nu.size() > 0) {
//         while (i < (int)nu.size()) {
//             int curr_max = 1;
//             int ele = nu[i];
//             // auto nxt_idx = find(nu.begin(), nu.end(), ele+1);
//             vector<int>::iterator nxt_idx;
//             while (nxt_idx != nu.end()) {
//                 nxt_idx = find(nu.begin(), nu.end(), ele + 1);
//                 if (nxt_idx > nu.begin() + i) {
//                     nu.erase(nxt_idx);
//                 }
//                 curr_max++;
//                 ele++;
//             }
//             global_max = max(global_max, curr_max);
//             // nu.erase(find(nu.begin(), nu.end(), nu[i]));
//             i++;
//         }
//         return global_max;
//     }
// };

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    Solution sol;

    cout << "Input: \n";
    for (int n : int_vec) {
        cout << n << " ";
    }
    cout << endl;

    int ans = sol.longestConsecutive(int_vec);
    cout << "Max consecutive: " << ans << endl;

    return 0;
}