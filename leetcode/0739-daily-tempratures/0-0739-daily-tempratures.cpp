// https://leetcode.com/problems/daily-temperatures/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        /*
        For each value find the next value that is higher that than i

        value at i+x is greater than value at i
        now find x,
        (or return 0 if no such value exist)

        and return an array that has x at each i in the given array

         */
        return ans;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    Solution sol;
    vector<int> ans = sol.dailyTemperatures(int_vec);

    for (auto n : ans) cout << n << " ";
    cout << "\n";
    cout << "Size: " << ans.size() << "\n";
}