#include <iostream>
using namespace std;

/*
Time complexity: O(n)
Space complexity: O(n)
*/

int sum_of_n(int n) {
    if (n == 1) {
        // base case
        return 1;
    }
    return n + sum_of_n(n - 1);
}

int main() {
    int n = 4;
    cout << "Sum of all nums from " << n << " to 1 is: " << sum_of_n(n) << endl;
    return 0;
}