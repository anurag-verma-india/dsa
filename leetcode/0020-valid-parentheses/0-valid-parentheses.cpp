// working
// not optimal
// https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        int n = s.size();
        printf("String: ");
        cout << s << "\n";
        stack<char> p;
        for (int i = 0; i < n; i++) {
            cout << s[i] << " ";
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    p.push(s[i]);
                    break;
                case ')':
                    if (p.empty())
                        return false;
                    if (p.top() == '(')
                        p.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (p.empty())
                        return false;
                    if (p.top() == '[')
                        p.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (p.empty())
                        return false;
                    if (p.top() == '{')
                        p.pop();
                    else
                        return false;
                    break;
            }
        }
        if (p.empty())
            return true;
        return false;
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
