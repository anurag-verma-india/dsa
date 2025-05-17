// Not completed (Wouldn't run in O(n) time)
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
    global count
    while not the end of the list
        while ele-1 exists
            count++
            remove ele-1 from the array
            ele--

        reset element
        while ele+1 exists
            count++
            remove ele+1 from array
            ele++

        update global count

---
complexity

space:

time:

*/

class Solution {
   public:
    int longestConsecutive(vector<int>& na) {
        int global_count = 0, i = 0;
        // Not using n because arr size is dynamic
        if (i < (int)na.size()) {
            int ele = na[i], count = 1;  // Counting the curr element

            vector<int>::iterator itr = find(na.begin() + i + 1, na.end(), ele);
            // Remove all duplicate instances
            ele = na[i];

            // Checking prev
            itr = find(na.begin() + i + 1, na.end(), ele - 1);
            while (itr != na.end()) {
                count++;
                na.erase(itr);
                ele--;
                itr = find(na.begin() + i + 1, na.end(), ele - 1);
            }
            ele = na[i];

            // Checkint next
            itr = find(na.begin() + i + 1, na.end(), ele + 1);
            while (itr != na.end()) {
                count++;
                na.erase(itr);
                ele++;
                itr = find(na.begin() + i + 1, na.end(), ele + 1);
            }
            ele = na[i];

            global_count = max(global_count, count);

            i++;
        }
        return global_count;
    }
};

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