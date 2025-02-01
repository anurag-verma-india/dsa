// https://leetcode.com/problems/generate-parentheses/
// https://www.youtube.com/watch?v=s9fokUqJ76A
// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0022-generate-parentheses.cpp

#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
/*
Generate all possible parentheses pairs with a given number n

(Solution possible with just stack)

backtracking (using a tree like structure to go through every solution)

 - Call a recursive function
 - First check if its ending condition (i.e. open & close = n, or strLen == 2*n) if yes then add the string to the answer array
 - then check if the opening parentheses are less then max allowed (given n)
    if yes then call this function recursively to essentially create a fork in the decision tree
 - then check if the opening parentheses are more than the closing ones (it means you can close some at thins point), so call function recursively and make another fork

At the end all the possible edges of this tree will be added to the answer array
*/

class Solution {
   private:
    void generator(int n, int open, int close, string s, vector<string>& ans) {
        if ((int)s.size() == 2 * n) {
            // if (open == n && close == n) {
            ans.push_back(s);
            return;
        }
        if (open < n) {
            generator(n, open + 1, close, s + "(", ans);
        }
        if (open > close) {
            generator(n, open, close + 1, s + ")", ans);
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generator(n, 0, 0, "", ans);
        return ans;
    }
};

int main() {
    file_as_stdin("input.txt");
    int n;
    cin >> n;
    // cout << n << "\n";
    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);
    for (auto str : ans) cout << str << " ";
    cout << "\n";
    return 0;
}