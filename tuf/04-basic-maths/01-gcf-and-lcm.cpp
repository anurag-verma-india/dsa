#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<long long> lcmAndGcd(long long a, long long b) {
        // code here
        long long num1 = a, num2 = b, gcd;
        while (a > 0 && b > 0) {
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        if (a == 0) {
            gcd = b;
        } else {
            gcd = a;
        }
        if (num1 > num2) {
            // vector<long long> vec =
            return {((num1 / gcd) * num2), gcd};
        } else {
            return {((num2 / gcd) * num1), gcd};
        }
        // return [lcm, gcd];
    }
};

int main() { return 0; }