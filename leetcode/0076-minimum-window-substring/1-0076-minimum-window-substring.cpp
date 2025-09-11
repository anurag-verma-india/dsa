
// https://leetcode.com/problems/minimum-window-substring/
// t: 8ms, 61%; s: 12mb, 84%;

#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string.cpp"

/*
Description:
    Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

    The testcases will be generated such that the answer is unique.

    Example 1:
    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

    Example 2:
    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.

    Example 3:
    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    Since the largest window of s only has one 'a', return empty string.

    Constraints:
    m == s.length
    n == t.length
    1 <= m, n <= 105
    s and t consist of uppercase and lowercase English letters.

input:
    string s: string to search
    string t: substring characters to be searched in s

output:
    string ans: min substr of s that contains all characters of t

approach:
    start with a map to keep track of all the characters that we need find in a substring (think of it as a char debt record)
    (freq map of all the chars in t)
    & a variable rem to keep track of the remaining characters that we need to find (init w/ len(t))

    initialize a substr window with 0 to INT_MAX
    (INT_MAX so that the next window we find will definitely be smaller than this)

    keep expanding the window until from the right until the rem is 0
    at this point we start decreasing the window from the left until we reach a left char is that 0
        at this point the program checks if the previous substring's length is larger than the current
            if yes then it's updated
            then we move the window 1 char to the right
            (deliberately make it invalid to check if any smaller valid substrings exist)

---
complexity
space: o(m+n)
    m, n: size of s, t
    counting chars: n, looping over s: m
time: O(m+n) | O(1)
    worst case every char in s, t is unique hashmap size if will be the larger of the two
    If we assume the char set is limited (e.g. ASCII, etc) then the hashmap size in worst case is every char of this finite set hence O(1)
*/
class Solution {
   public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();

        if (sn < tn) {
            return "";
        }

        unordered_map<char, int> char_map;
        vector<int> min = {0, INT_MAX};
        int total_rem = tn;

        for (char c : t) {
            char_map[c]++;
        }

        int l = 0;
        for (int r = 0; r < sn; r++) {
            char ch = s[r];
            if (char_map.find(ch) != char_map.end() && char_map[ch] > 0) {
                total_rem--;
            }
            char_map[ch]--;

            if (total_rem == 0) {
                // Decreasing the window from the left
                while (true) {
                    if (char_map.find(s[l]) != char_map.end() && char_map[s[l]] + 1 <= 0) {
                        char_map[s[l]]++;
                        l++;
                    } else
                        break;
                }

                if (r - l < min[1] - min[0]) {
                    min[0] = l;
                    min[1] = r;
                }
            }
        }
        return min[1] - min[0] == INT_MAX ? "" : s.substr(min[0], min[1] - min[0] + 1);
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<string> str = read_string();
    Solution sol;

    string min_substr = sol.minWindow(str[0], str[1]);

    printf("\nMin substring of \"%s\" in \"%s\" is: \"%s\"\n\n", str[0].c_str(), str[1].c_str(), min_substr.c_str());  // s, t, substr

    return 0;
}