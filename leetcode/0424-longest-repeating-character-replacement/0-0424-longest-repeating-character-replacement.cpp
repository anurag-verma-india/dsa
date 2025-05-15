// Not valid
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
    sliding window

    while r < n: 
        

---
complexity
time: 

space: 


*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        cout << "String: " << s << "\n";
        cout << "k: " << k << "\n";
        return 0;
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

    int ans = sol.characterReplacement(s,k);

    cout << "Output: " << ans << "\n";
}