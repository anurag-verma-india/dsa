// https://leetcode.com/problems/sum-of-digits-in-base-k/description/
// https://leetcode.com/problems/sum-of-digits-in-base-k/solutions/6639020/beat-100-solutions-by-subhu04012003-byql/
#include <iostream>
using namespace std;

/*
ip:
    int n: number to be converted
        1 <= n <= 100
    int k: base to convert to
        2 <= k <= 10

op:
    int sum: sum of all digits after conversion from base 10 to base k

approach:
    We don't need the number itself after conversion we just need the sum

    repeatedly calculate mod k of num, and divide the number by k
    Keep a sum variable that has sum of all the mods calculated

    (Since the number in base k is the result after keeping track of all these remainders
    and then reversing their order)

---
T&S Complexity

*/

class Solution {
   public:
    int sumBase(int n, int k) {
        int sum = 0;
        while (n > 0) {
            sum += (n % k);
            n /= k;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    // int n = 34;
    // int k = 6;
    int n = 10, k = 10;
    int sum = sol.sumBase(n, k);
    cout << "Sum of digits of " << n << " in base " << k << " is " << sum << endl;
    return 0;
}