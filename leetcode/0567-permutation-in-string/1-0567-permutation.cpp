// t: 1ms, 77%; s: 11mb, 23%;
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
    the problem boils down to if s2 contains a substring that has the same character frequency as s1

    slide a window over s2 of len(s1) and match with the frequency map of s1
    if matched at any point return true

    if none match then return false
---
complexity
space: 
time:
*/
class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        // s2 contains a permutation of s1
        if ((int)s2.size() < (int)s1.size()) return false;
        unordered_map<char, int> s1count;
        unordered_map<char, int> s2count;

        for (int i = 0; i < (int)s1.size(); i++) {
            s1count[s1[i]]++;
            s2count[s2[i]]++;
        }
        if (s1count == s2count) return true;

        int left = 0;
        for (int right = (int)s1.size(); right < (int)s2.size(); right++) {
            s2count[s2[right]]++;
            s2count[s2[left]]--;
            if (s2count[s2[left]] == 0) {
                s2count.erase(s2[left]);
            }
            left++;
            if (s1count == s2count) {
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
