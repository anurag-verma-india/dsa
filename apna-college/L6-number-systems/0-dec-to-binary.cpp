// Unfinished

#include <bits/stdc++.h>
using namespace std;

int main() {
    int decNum = 5;

    int ans = 0;
    int power = 1;

    while (decNum > 0) {
        int rem = decNum % 2;
        decNum = decNum / 2;
        ans = rem * power;
        power *= 10;
    }

    cout << "Converted Binary number: " << ans << "\n";

    return 0;
}