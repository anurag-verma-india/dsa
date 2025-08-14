// https://leetcode.com/problems/valid-palindrome/
// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0125-valid-palindrome.cpp

#include <bits/stdc++.h>

#include "./read.cpp"
using namespace std;
/*
Go outside-in form the left and right edge of the string
Compare the characters (unless it's a special character)
Skip any non character

Edge case:
i is out of range (i>n)
j is out of range (j<0)

*/

class Solution {
   public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    // stdin now reads from input.txt
    // Debugging from passing input.txt though bash was not working for some reason
    // freopen("input.txt", "r", stdin);
    read_input("input.txt");
    Solution sol;
    string sin;
    getline(cin, sin);  // red the first line

    cout << sol.isPalindrome(sin) << "\n";

    return 0;
}