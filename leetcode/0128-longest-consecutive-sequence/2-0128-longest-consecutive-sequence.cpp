// T 28, S 66
// https://leetcode.com/problems/longest-consecutive-sequence
// https://leetcode.com/problems/longest-consecutive-sequence/solutions/6398280/video-check-n-1-by-niits-b1u0/
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
    convert list to unordered set
    (find in unordered_set has O(1) time complexity)

    for each ele in the set
        if it's the start of a consecutive sequence
        (i.e. ele-1 is not present int the array)
            count = 1
            while ele+count present in the set
                count++

        global_count = max(global, count)

---
complexity

space:

time:

*/

class Solution {
   public:
    int longestConsecutive(vector<int>& na) {
        unordered_set<int> nSet(na.begin(), na.end());
        int global_count = 0;

        for (int n : nSet) {
            int count = 0;
            if (nSet.find(n - 1) == nSet.end()) {
                count = 1;
                while (nSet.find(n + count) != nSet.end()) count++;
            }
            global_count = max(global_count, count);
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