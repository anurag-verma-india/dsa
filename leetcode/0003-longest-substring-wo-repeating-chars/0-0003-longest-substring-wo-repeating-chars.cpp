
// Not optimal, Beats T 20, S 7
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"

/*
input:
    string

output:
    int: length of longest substring without repeating characters

approach:

    for each character
        if the character appears in the current substring
            save the max b/w max_len & current length as highest
            update the substring by removing till the first appearance of the current character
        else add the character to the current substring

---
complexity:

space:

time:
*/
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int curr_start = 0, n = s.size();

        switch (n) {
            case 0: {
                // If passed string is empty
                return 0;
                break;
            }
            case 1: {
                // if passed string only has one character
                return 1;
                break;
            }
        }

        int max_substring = 0;
        string current_substring = s.substr(curr_start, 1);  // starting from 0 string of length 1

        for (int i = 1; i < n; i++) {
            int idx = current_substring.find(s[i]);
            if (idx != (int)string::npos) {  // Current character is present in the substring
                max_substring = max(max_substring, (int)current_substring.size());
                current_substring = current_substring.substr(idx + 1, (int)current_substring.size() - (idx - 1));
                current_substring.push_back(s[i]);
            } else {
                // Current character is not present in the substring
                current_substring.push_back(s[i]);
            }
        }
        return max(max_substring, (int)current_substring.size());
    }
};

int main() {
    file_as_stdin("input.txt");

    int n;
    string str;

    cin >> n;      // Get number of characters
    cin.ignore();  // Ignore the new line character at the end of line
    getline(cin, str);
    if ((int)str.length() > n) str = str.substr(0, n);
    // If string length is greater then the intended given, ignore the trailing characters

    Solution sol;

    int length = sol.lengthOfLongestSubstring(str);

    cout << "Length: " << length << "\n";

    return 0;
}
