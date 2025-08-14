// accepted, not optimal
// https://leetcode.com/problems/valid-palindrome/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isPalindrome(string s) {
        string ps = "";
        for (int i = 0; i < (int)s.size(); i++) {
            if (isalnum(s[i])) ps.push_back(tolower(s[i]));
        }
        int i = 0;
        int j = ps.size() - 1;

        cout << ps << "\n";
        while (j > i) {
            if (ps[i] != ps[j]) {
                return false;
            }
            j--;
            i++;
        }
        return true;

        // cout << "\n";
    }
};

int main() {
    // stdin now reads from input.txt
    // Debugging from passing input.txt though bash was not working for some reason
    freopen("input.txt", "r", stdin);
    Solution sol;
    string sin;
    getline(cin, sin);

    cout << sol.isPalindrome(sin) << "\n";

    return 0;
}