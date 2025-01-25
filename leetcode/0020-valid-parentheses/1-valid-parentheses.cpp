#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        // int n = s.size();
        unordered_map<char, char> hash = {{')', '('},
                                          {']', '['},
                                          {'}', '{'}};
        stack<char> p;
        for (auto c : s) {
            if (hash.count(c)) {
                if (!p.empty() && p.top() == hash[c]) {
                    p.pop();
                } else {
                    return false;
                }
            } else {
                p.push(c);
            }
        }
        if (!p.empty()) return false;
        return true;
    }
};

int main() {
    // input.txt as stdin
    if (!freopen("input.txt", "r", stdin)) {
        cout << "There was a problem opening the input file";
        exit(1);
    }
    string str;
    getline(cin, str);
    // --------------------------------
    // cout << str;
    // printf("\n");

    Solution sol;
    cout << sol.isValid(str) << "\n";

    return 0;
}
