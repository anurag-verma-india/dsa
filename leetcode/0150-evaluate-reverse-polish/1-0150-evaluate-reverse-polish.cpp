
// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0150-evaluate-reverse-polish-notation.cpp
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string.cpp"

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < (int)tokens.size(); i++) {
            string token = tokens[i];
            if (token.size() > 1 || isdigit(token[0])) {
                stk.push(stoi(token));
                continue;
            }
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            int result = 0;
            if (token == "+")
                result = num1 + num2;
            else if (token == "-")
                result = num1 - num2;
            else if (token == "*")
                result = num1 * num2;
            else if (token == "/")
                result = num1 / num2;
            stk.push(result);
        }
        return stk.top();
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<string> str = read_string();
    Solution sol;
    cout << "Output: " << sol.evalRPN(str) << "\n";
}