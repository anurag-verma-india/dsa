// https://leetcode.com/problems/daily-temperatures/
// https://leetcode.com/problems/daily-temperatures/solutions/6027677/video-stack-solution-python-javascript-j-vndw/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Keep a stack and add the current day's position in the stack

while the stack is not empty keep checking
    if the temperature of the current day is greater than that on the top of the stack
    calculate the difference and add that to the final answer

    after this add the current day's position to the stack
*/

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> pvStk;

        for (int i = 0; i < n; i++) {
            while (!pvStk.empty() && temperatures[i] > temperatures[pvStk.top()]) {
                // int prevDay = pvStk.top();
                result[pvStk.top()] = i - pvStk.top();
                pvStk.pop();
            }
            pvStk.push(i);
        }

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