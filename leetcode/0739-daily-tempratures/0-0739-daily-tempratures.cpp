// did not try to solve by myself
// https://leetcode.com/problems/daily-temperatures/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());

        return result;
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