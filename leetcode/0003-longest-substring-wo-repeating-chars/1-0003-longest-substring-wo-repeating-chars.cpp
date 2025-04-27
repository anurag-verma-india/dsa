// Beats T 31, S 31
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/5111376/video-3-ways-to-solve-this-question-sliding-window-set-hashing-and-the-last-position/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"

/*
input:
    string

output:
    int: length of longest substring without repeating characters

approach:
    sliding window and set

    keep a set with all the characters in the string
    start the window at 0,0
        check if the current character is in the set
            while there is one
                keep moving left pointer by one position to the right & removing the character form the set
                (since there all character in the stirng up until this point were unique the only repeating character is the current one)
        then add the current character to the set
        Save to prev-max the max between prev-max and current length

    return the calculated prev-max


---
complexity:
time: O(n)
    since the right and left pointer can traverse the entire string at most once
    O(2n) = O(n)
    // https://gemini.google.com/app/4a4e9e7de6936b0e

space: O(1)
    unordered set can contain upto n unique characters
    but since the character set is limited (i.e. ascii) number of unique characters is constant
    therefore n is very small
    O(n) = O(1) [since n is constant, due to limited character set]
    // https://gemini.google.com/app/4a4e9e7de6936b0e
    

*/
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        // cout << "Current string: " << s << "\n";
        int left = 0, right = 0, prevMax = 0, n = s.size();
        unordered_set<int> chars;

        while (right < n) {
            while (chars.find(s[right]) != chars.end()) {
                // The character at right end is already in the current substring
                chars.erase(s[left]);
                left++;
            }
            prevMax = max(prevMax, right - left + 1);  // right - (left - 1)
            chars.insert(s[right]);
            right++;
        }
        return prevMax;
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
