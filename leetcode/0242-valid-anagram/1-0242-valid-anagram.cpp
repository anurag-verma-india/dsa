
// s: 7ms, 20%; t: 10mb, 11%;
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
    if the strings are of same length
    loop through both the strings at the same time and make a hashmap

    if hashmaps are equal return true
    otherwise false

---
complexity

space:

time:

*/

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if ((int)s.size() != (int)t.size()) return false;
        int n = s.size();
        unordered_map<char, int> freq_s;
        unordered_map<char, int> freq_t;
        for (int i = 0; i < n; i++) {
            freq_s[s[i]]++;
            freq_t[t[i]]++;
        }
        if (freq_s == freq_t) return true;
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