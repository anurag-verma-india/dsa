#include <bits/stdc++.h>
using namespace std;

// input  0 1 2 3 4 5 6  7 ...
// output 0 1 1 2 3 5 8 13 ...
class Solution {
   public:
    // with recursion, not good
    int fib_with_recursion(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return fib_with_recursion(n - 1) + fib_with_recursion(n - 2);
    }
    int fib(int n) {
        if ((n == 0) || (n == 1)) return n;
        int a = 0, b = 1, c = 0;
        for (int i = 1; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    if (!freopen("input.txt", "r", stdin)) cout << "There was an error opening input.txt";
    Solution sol;
    int n;
    cin >> n;
    cout << "fib_with_recursion(" << n << ") = " << sol.fib(n) << "\n";
    return 0;
}