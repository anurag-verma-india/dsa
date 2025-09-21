
// not efficient
// https://leetcode.com/problems/valid-anagram/description/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string.cpp"

/*
Description:
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

    Example 2:
    Input: s = "rat", t = "car"
    Output: false

    Constraints:
    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

    Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

input:
    string s: first string
    string t: second string

output:
    bool ans: true if t is an anagram of s, otherwise false

approach:
    first check if s and t are equal length
    if they are sort their characters
    if the strings are the same after the sorting then return true
    otherwise return false

---
complexity

space:

time:

*/

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if ((int)s.size() == (int)t.size()) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if (s == t) return true;
        }
        return false;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<string> str = read_string();

    Solution sol;
    bool isAna = sol.isAnagram(str[0], str[1]);
    string ans = isAna ? "true" : "false";

    cout << endl;
    cout << "s: " << str[0] << endl
         << "t: " << str[1] << endl;
    cout << "s is an anagram of t: " << ans << endl;
    cout << endl;

    return 0;
}