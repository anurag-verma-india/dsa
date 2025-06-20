// https://leetcode.com/problems/convert-to-base-2/description/
// https://leetcode.com/problems/convert-to-base-2/solutions/265507/javacpython-2-lines-exactly-same-as-base-3prp/
// https://chatgpt.com/share/68559109-00a4-800b-9a0d-aca5c7e77dfd
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
// #include "./read_int.cpp"

/*
Description:
    Given an integer n, return a binary string representing its representation in base -2.
    Note that the returned string should not have leading zeros unless the string is "0".

    Example 1:

    Input: n = 2
    Output: "110"
    Explanation: (-2)^2 + (-2)^1 = 2
    Example 2:

    Input: n = 3
    Output: "111"
    Explanation: (-2)^2 + (-2)^1 + (-2)^0 = 3
    Example 3:

    Input: n = 4
    Output: "100"
    Explanation: (-2)^2 = 4


    Constraints:
    0 <= n <= 10^9

input:
    int n: number
    convert to base -2

output:
    string num: string representation of the given number (w/o leading zeros)

approach:

    repeatedly calculate mod -2 of the number in the following way:
        calculate the mod 2 of the number 
        divide the number by 2 and also multiply by -1 (i.e. divide by -2)



0 => 0
1 => 1
10 => -2
11 => -1
100 => 4
101 => 5
110 => 2
111 => 3
1000 => -8
1001 => -7
1010 => -10
1011 => -9

---
complexity

space:

time:

*/
class Solution {
   public:
    string baseNeg2(int n) {
        // string b2n = "";
        // while (n > 0) {
        //     int rem = n % 2;
        //     // b2n = to_string(rem) + b2n;
        //     if (rem == 0)
        //         b2n = "0" + b2n;
        //     else
        //         b2n = "1" + b2n;
        //     n = -(n >> 1);
        // }
        // return b2n;
        string res;
        while (n) {
            res = to_string(n & 1) + res;  // n & 1 is equivalent to n % 2 but faster
            ;                              // and we are adding the result to the front because we need to reverse the order of mod operation results
            n = -(n >> 1);                 // Divide by -2 (base is -2)
            ;                              // [Shift 1 position to right and also negate the output]
        }
        return res == "" ? "0" : res;
    }
};

int main() {
    file_as_stdin("input.txt");
    // vector<int> int_vec = read_int();
    int n;
    cin >> n;
    Solution sol;
    string b2n = sol.baseNeg2(n);
    cout << "Base -2 of " << n << " is " << b2n << endl;
    return 0;
}