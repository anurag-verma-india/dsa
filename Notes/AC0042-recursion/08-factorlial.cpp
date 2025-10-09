#include <iostream>
using namespace std;

int factorial(int n) {
    // print factorial
    if (n == 0) return 1;  // since, 0! = 1
    // cout << n * factorial(n - 1) << " ";
    return n * factorial(n - 1);
}

int main() {
    int n = 5;
    cout << "factorial of " << n << " is " << factorial(n) << endl;

    return 0;
}