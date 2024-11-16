// https://leetcode.com/problems/reverse-integer/submissions/1454242179/
// accepted
#include <bits/stdc++.h>
using namespace std;

// 2e31 = 2147483648
class Solution {
   public:
    int reverse(int x) {
        // Because the input could result in int overflow
        long rev = 0;
        // No need to check negative the formula works for it too

        // bool isNegative = false;
        // if (x < 0) {
        //     isNegative = true;
        //     x = x * -1;
        // }
        // while (x != 0) {
        while (x) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        if (rev > INT32_MAX || rev < INT32_MIN) return 0;
        // if (isNegative) return rev * -1;
        return rev;
    }
};

int main() {
    Solution sol = Solution();
    int num;

    cin >> num;

    cout << sol.reverse(num) << "\n";
}