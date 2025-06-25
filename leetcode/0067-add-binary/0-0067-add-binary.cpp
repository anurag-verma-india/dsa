
// https://leetcode.com/problems/add-binary/description/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string.cpp"

/*
Description:
    Given two binary strings a and b, return their sum as a binary string.



    Example 1:

    Input: a = "11", b = "1"
    Output: "100"
    Example 2:

    Input: a = "1010", b = "1011"
    Output: "10101"


    Constraints:

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.


input:
    string a
    string b
    Binary representations of strings

output:
    string sum: sum of a & b

approach:
    take the max of both strings append 0s to smaller number
    start from last of both strings if both
        // if carry and both digits are 1 append 1 and keep carry to be 1
        // if both 1s add 1 to carry put append 0 in sum
        // if both 0s append 0 to sum
        // if one of them is 1 append 1 to string
        // (append all at the front)

        Count 1s in carry a and b
        if (count == 3) append 1 and make carry 1
        if count count == 2, append 0, make carry 1
        if cout == 1, append 1, make carry 0

    outside loop check if carry is 1 append 1 to sum


---
complexity

space:

time:

*/

class Solution {
   public:
    string addBinary(string a, string b) {
        // Ensure a is always smaller one
        if (a.length() > b.length()) {
            return addBinary(b, a);
        }
        cout << "a: " << a << "\nb: " << b << "\n";
        string sum = "";
        // Making a and b be equal length
        string leadingZeros = string(b.length() - a.length(), '0');
        // cout << "-----\n";
        // cout << leadingZeros << "\n";
        cout << "\nleading 0s: "
             << leadingZeros << "\n";
        cout << "a: " << a << "\n";
        a = leadingZeros + a;
        cout << "a: " << a << "\n";

        int n = a.length();
        string carry = "0";
        int count = 0;
        for (int i = n - 1; i <= 0; i--) {
            // if (carry == "1" && a[i] == '1' && b[i] == '1') {
            //     sum = "1" + sum;
            // } else if (carry == "0" && a[i] == '1' && b[i] == '1') {
            //     sum = "0" + sum;
            //     carry = "1";
            count = 0;
            if (carry == "1") count++;
            if (a[i] == '1') count++;
            if (b[i] == '1') count++;

            if (count == 3) {
                carry = "1";
                sum = "1" + sum;
            } else if (count == 2) {
                carry = "1";
                sum = "0" + sum;
            } else if (count == 1) {
                carry = "0";
                sum = "1" + sum;
            } else {
                carry = "0";
                sum = "0" + sum;
            }
        }
        if (carry == "1") sum = "1" + sum;

        return sum;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<string> str = read_string();
    Solution sol;

    // sol.addBinary("1", "110");
    // string ans = sol.addBinary(str[0], str[1]);
    string ans = sol.addBinary("11", "1");
    cout << str[0] << " + " << str[1] << " \n";

    return 0;
}