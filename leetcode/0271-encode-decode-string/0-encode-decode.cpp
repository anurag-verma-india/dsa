// https://neetcode.io/problems/string-encode-and-decode

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string encode(vector<string>& strs) {
        /*
        - if input array is empty return an empty string
        # is value separator
        ^ is escape character

        - Loop through each value in the array
        - If the item contains # or ^
            - Loop through each character in the string item
            - if the character is control character add it's escaped version
            - otherwise simply add the character to the ans
            - Add # after the string item is finished
        - If the string item doesn't contain control character
            - Simply add the whole item to the ans
            - Add a # after each string
        */
        int n = strs.size();
        if (strs.size() <= 0) return "";
        string ans = "";
        for (int i = 0; i < n; i++) {
            // If c is not present in string.find(c) -> string::npos is returned
            if ((strs[i].find("#") != string::npos) || (strs[i].find("^") != string::npos)) {
                string c = strs[i];
                int c_len = c.size();
                for (int j = 0; j < c_len; j++) {
                    if (c[j] == '#') {
                        ans.append("^#");
                    } else if (c[j] == '^') {
                        ans.append("^^");
                    } else
                        ans.append(string(1, c[j]));
                    if (j == c_len - 1) ans.append("#");
                }
            } else {
                ans.append(strs[i]);
                ans.append("#");
            }
        }

        return ans;
    }

    vector<string>
    decode(string s) {
        /*
        - If the input string is empty, return a empty array

        - Loop through each character in the given string
        - If the character is a control character (# or ^)
            - First check escape character cases
            - Then check the normal functions of the characters
        - If the character si not a control character
            - Simply add it to the current array

        */
        vector<string> ans(0);
        int n = s.size();
        if (n == 0) {
            vector<string> a = {};
            return a;
        }
        ans.push_back("");
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '^') {
                // If the char is escape character
                if (s[i + 1] == '^') {
                    // if char after escaped char is ^
                    ans[k].push_back('^');
                    i++;  // to skip the next character, we already checked it
                } else if (s[i + 1] == '#') {
                    // if char after escaped char is #
                    ans[k].push_back('#');
                    i++;  // to skip the next character, we already checked it
                }
            } else if ((s[i] == '#') && (i != n - 1)) {
                // if char is separator char and it's not last element
                ans.push_back("");
                k++;
            } else if ((s[i] == '#') && (i == n - 1)) {
                // if char is separator char and it's last element
                // do nothing
            } else {
                // If the character is not one of the control character
                ans[k].push_back(s[i]);
            }
        }
        return ans;
    }
};

int main() {
    if (!freopen("input.txt", "r", stdin)) {
        cout << "There was a problem opening the input file";
        exit(1);
    }

    // Read strings of arrays
    int n = 0;
    vector<string> inp;
    cin >> n;
    // cout << "n: " << n << "\n";
    string temp;
    getline(cin, temp);
    while (n--) {
        getline(cin, temp);
        inp.push_back(temp);
    }

    Solution sol;
    string encoded = sol.encode(inp);
    cout << "\nEncoded string: " << encoded << "\n";

    vector<string> decoded = sol.decode(encoded);
    printf("Decoded string\n");
    for (auto st : decoded) cout << "\"" << st << "\"" << ", ";
    printf("\n");

    if (inp == decoded)
        cout << "Decoding success\n";
    else
        cout << "Decoding failed\n";

    // ---------------- Empty checks
    // Solution sol;
    // // vector<string> a = {};
    // vector<string> a = {""};
    // cout << "Encoded size: " << a.size() << "\n";
    // string encoded = sol.encode(a);
    // cout << "Encoded:" << encoded << "-\n";
    // vector<string> decoded = sol.decode(encoded);
    // cout << "Decoded size: " << decoded.size() << "\n";
    // printf("Decoded:");
    // for (auto st : decoded) cout << st << "-";
    // cout << "-\n";

    return 0;
}