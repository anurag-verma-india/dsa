// https://leetcode.com/problems/daily-temperatures/
// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0739-daily-temperatures.cpp
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
For each day

check if the stack is not empty

if not
then check if the current day's temperature is greater then top of stack
if it is greater (warmer) then pop from the top of the stack
    subtract the previous day from the current one
    (to get number of days to wait for warmer temp)
    add that to the result vector (on previous day's position)
    do this until the stack is empty
 */

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        // {dayNumber, temperature}
        stack<pair<int, int>> previousStk;

        for (int i = 0; i < n; i++) {
            int currDay = i;
            int currTemp = temperatures[i];
            while (!previousStk.empty() && previousStk.top().second < currTemp) {
                int prevDay = previousStk.top().first;
                // int prevTemp = previousStk.top().second;
                previousStk.pop();

                result[prevDay] = currDay - prevDay;
            }
            previousStk.push({currDay, currTemp});
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