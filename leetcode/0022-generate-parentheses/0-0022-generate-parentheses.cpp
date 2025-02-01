// https://leetcode.com/problems/generate-parentheses/
// unable to solve, not really tried

#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        /*
        Generate all possible parentheses pairs with a given number n
        */
        stack<string> st;
        vector<string> vec;
        for (int i = 0; i < n; i++) {
            // vec[0].push_back()
        }
    }
};

int main() {
    file_as_stdin("input.txt");
    int n;
    cin >> n;
    cout << n << "\n";
}