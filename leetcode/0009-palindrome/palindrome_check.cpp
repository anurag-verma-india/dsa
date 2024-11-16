#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long rev = 0;
        int num = x;
        while (x) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        // cout << rev << "\n";
        if (rev == num) return true;
        return false;
    }
};

int main() {
    Solution sol;
    int num;
    cin >> num;
    cout << sol.isPalindrome(num) << "\n";

    return 0;
}