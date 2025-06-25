#include <bits/stdc++.h>
using namespace std;

int findGCD(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if (a == 0) return b;
    return a;
}

int main() {
    int n1 = 20, n2 = 15;
    int GCD = findGCD(n1, n2);
    cout << "GCD of " << n1 << " & " << n2 << " is " << GCD << "\n";
    return 0;
}