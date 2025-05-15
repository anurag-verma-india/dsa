// Beats T 100, S 20
// https://leetcode.com/problems/longest-repeating-character-replacement/solutions/4200234/o-n-c-step-by-step-explanation-by-monste-gujo/
// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0424-longest-repeating-character-replacement.cpp
// https://leetcode.com/problems/longest-repeating-character-replacement
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
// #include "./read_string.cpp"

/*
Problem description:
You are given a string s and an integer k.
You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

intput:
    string s: string of input characters
    int k: number of characters that you can change

output:
    int num: longest substring of repeating characters after replacement of k characters

approach:
    sliding window and hashmap

    loop for the size of the window (loop var is right pointer)
        update freq of char at r ptr in map
        update the max frequency in the map

        if [(length of the window - max_freq) > k]
            // we will have more different chars left after k replacements for the current max character
            // or previous max, in case of stale max
            // In either case
            decrease the freq in map of left pointer
            move left pointer to right

        else
            // We can make k replacement since non-manfreq char are less then k
            // We only ever update the max when the (len - max_f is smaller than k)
            update ans = max between max_val and window size

    return ans
---
complexity
time:
    O(n)
    // Since only one loop from 0 to n-1

space:
    O(1)
    // Since freq map will always be map of 26 chars
*/

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0, maxf = 0, n = s.size(), ans = 0;
        vector<int> freq_map(26, 0); // Always represents the state of current substring

        for (int r = 0; r < n; r++) {
            freq_map[s[r] - 'A']++;
            maxf = max(maxf, freq_map[s[r] - 'A']);

            if ((r - l + 1 - maxf) > k) {
                freq_map[s[l] - 'A']--;
                l++;  // Move left ptr
            } else {
                ans = max(ans, (r - l + 1));
            }
        }
        return ans;
    }
};

int main() {
    file_as_stdin("input.txt");
    // vector<string> str = read_string();
    string s;
    int k;
    cin >> s;
    cin >> k;

    Solution sol;

    int ans = sol.characterReplacement(s, k);

    cout << "Output: " << ans << "\n";
}