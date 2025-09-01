// not working
// https://leetcode.com/problems/permutation-in-string/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string.cpp"

/*
Description:
    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    In other words, return true if one of s1's permutations is the substring of s2.

    Example 1:

    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").
    Example 2:

    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false

input:
    string s1, s2: input string

output:
    bool ans: true if s2 contains a permutations of s1

approach:
    create a set permutations that contains all permutations of s1
    iterate over each permutation of s1
    -----
    ts1 = s1
    left = idx of first character present in ts1
    right = left
    while right < s2.size():
        if right + 1 present in ts1:
            remove r+1 from ts1
            right++
        otherwise:
            reset ts1
            left = idx of next character present in ts1 (start checking from r+2 if it exists)

        if ts1.size == 0: return True

    return False


---
complexity
space:
time:
*/
class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n1 = (int)s1.size();
        int n2 = (int)s2.size();
        int left = -1, right = -1;
        for (int i = 0; (i < n1 && left == -1); i++) {
            left = s2.find(s1[i]);
        }
        if (left == string::npos || left == -1) return false;
        right = left;

        string ts1 = s1;
        while (right < n2) {
            if (left == string::npos || left == -1) return false;
            // right + 1 idx char present in ts1 remove it; right++
            int idx = ts1.find(s2[right + 1]);

            if (idx != string::npos) {
                ts1.erase(idx);
                right++;
            }
            if ((int)ts1.size() == 0) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<string> str = read_string();
    // string a = "ab";
    // string inp_str = str[0];
    // cout << inp_str << ": " << (int)inp_str.size() << endl;

    Solution sol;

    string ans = sol.checkInclusion(str[0], str[1]) ? "true" : "false";

    cout << endl;
    cout << "\"" << str[0] << "\"" << " premutation present in " << "\"" << str[1] << "\"" << ": " << ans << endl;
    cout << endl;
    return 0;
}
