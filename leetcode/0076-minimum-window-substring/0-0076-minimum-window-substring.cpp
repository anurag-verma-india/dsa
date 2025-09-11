
// https://leetcode.com/problems/minimum-window-substring/
// t: 261ms, 6%; s: 372.28 MB, 6%;

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
    keep a frequency map of characters in the string

    start a window in s that starts and ends at the first character

        keep expanding the window until there is a case that all char freq in the s_count is higher then the t_count

        in that case start decreasing the size of the window from the left until the frequency is higher

    if the string is over and still the frequency is not higher return an empty string
---
complexity
space:
time:
*/
class Solution {
   public:
    string minWindow(string s, string t) {
        int ss = s.size();
        int ts = t.size();

        if (ts > ss) return "";

        unordered_map<char, int> s_count;
        unordered_map<char, int> t_count;

        for (int i = 0; i < ts; i++) {
            t_count[t[i]]++;
        }

        int l = 0;
        string ans = "";
        for (int r = 0; r < ss; r++) {
            // increase the size of the window and add that to the s_count
            s_count[s[r]]++;

            // check if the s_count contains all characters and their freq is higher than in t_count
            // if yes then start decreasing the window size
            // (since ans is unique we only need to find the first one)

            bool all_greater = true;
            for (auto freq : t_count) {
                // even if only one pair of the t_count is smaller set the flag to false
                if (s_count[freq.first] < freq.second) {
                    all_greater = false;
                    break;
                }
            }
            if (all_greater) {
                // the case where freq of all the chars in t are greater than in the window
                // decrease the size of the window from the left until the freq is greater
                while (s_count[s[l]] - 1 >= t_count[s[l]]) {
                    s_count[s[l]]--;
                    l++;
                }
                string new_ans = s.substr(l, r - l + 1);

                if (ans == "" || (ans.size() > new_ans.size())) {
                    ans = new_ans;
                }
            }
        }

        // return "";  // return empty string if none is found
        return ans;
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