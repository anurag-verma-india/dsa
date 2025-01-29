
// https://leetcode.com/problems/evaluate-reverse-polish-notation/
// from the 100% answer on leetcode solution
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string.cpp"

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto& token : tokens) {
            if (
                token == "+" ||
                token == "-" ||
                token == "*" ||
                token == "/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if (token == "+")
                    stk.push(a + b);
                else if (token == "-")
                    stk.push(a - b);
                else if (token == "*")
                    stk.push(a * b);
                else if (token == "/")
                    stk.push(a / b);
            } else {
                stk.push(stoi(token));
            }
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