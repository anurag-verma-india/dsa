
// t: 1ms - 100%, s: 8mb - 18%
// https://leetcode.com/problems/power-of-four/description/?envType=daily-question&envId=2025-08-15
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
----
Description:
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true

Constraints:

-231 <= n <= 231 - 1

Follow up: Could you solve it without loops/recursion?
----
input:
    int n: given number

output:
    bool ans: true if n is power of 4 otherwise false

approach:
    calculate log base 4 of the number, if an integer return true otherwise false

---
complexity

space:

time:

*/

class Solution {
   public:
    bool isPowerOfFour(int n) {
        float f = log(n) / log(4);  // log base 4 of number
        return isinf(f) ? false : f == floor(f);
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    int n = int_vec[0];

    // Solution sol(4);
    Solution sol{};
    string ans = sol.isPowerOfFour(n) ? "true" : "false";

    cout << n << " is a power of 4: " << ans << endl;
    return 0;
}