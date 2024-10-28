#include <bits/stdc++.h>
using namespace std;

int findGCD(int n1, int n2) {
    int largerNum = max(n1, n2), smallerNum = min(n1, n2), GCD = -1;

    while (smallerNum - GCD != 0) {
        GCD = largerNum - smallerNum;
        largerNum = max(smallerNum, GCD);
        smallerNum = min(smallerNum, GCD);
    }
    return GCD;
}

int main() {
    int n1 = 20, n2 = 15;

    int GCD = findGCD(n1, n2);

    cout << "GCD of " << n1 << " & " << n2 << " is " << GCD << "\n";

    return 0;
}