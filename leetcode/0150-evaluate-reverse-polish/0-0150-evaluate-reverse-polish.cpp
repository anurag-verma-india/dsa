#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string.cpp"

/*
Operators: + - * /

If number push to stack
operator pop and put top variable to temp
    then do operation with top of the stack
*/
// enum Oprts {
//     ADD,
//     SUB,
//     MUL,
//     DIV
// };
// Oprts getEnum(string s) {
//     if (s == "+")
//         return ADD;
//     else if (s == "-")
//         return SUB;
//     else if (s == "*")
//         return MUL;
//     else if (s == "/")
//         return DIV;
//     else
//         cout << "Error unknown string: \n"
//              << s;
// }

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int final_ans;
        int n = tokens.size();
        stack<string> stc;
        set<string> operators = {"+", "-", "*", "/"};
        for (int i = 0; i < n; i++) {
            // Check if the current value is in operator or not
            if (operators.find(tokens[i]) != operators.end()) {
                int temp = stoi(stc.top());
                stc.pop();
                int ans = 0;
                if (tokens[i] == "+") {
                    ans = stoi(stc.top()) + temp;
                } else if (tokens[i] == "-") {
                    ans = stoi(stc.top()) - temp;
                } else if (tokens[i] == "*") {
                    ans = stoi(stc.top()) * temp;
                } else if (tokens[i] == "/") {
                    ans = stoi(stc.top()) / temp;
                } else
                    cout << "Something went wrong";
                stc.pop();
                stc.push(to_string(ans));
            } else
                stc.push(tokens[i]);
        }
        final_ans = stoi(stc.top());
        return final_ans;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<string> str = read_string();
    Solution sol;
    cout << "Output: " << sol.evalRPN(str) << "\n";
}