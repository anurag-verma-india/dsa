// Unfinished

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;
/*
input
    int num: decimal number

output
    int binary_num: binary representation of given int

approach
    repeatedly divide given num by 2
    multiply the remainder of that operation by position of that number (starting from 1 [0s], 10, [2s], 100, [4s])
    and add that to the final ans variable
    keep track of current position by multiplying the position variable by 10 (or base [i.e. 2 ] in binary)

Time & Space Complexity
*/

int dec_to_bin(int n) {  // Number
    int b = 0;           // Binary

    int p = 1;  // position
    while (n > 0) {
        int r = n % 2;  // remainder
        b += r * p;
        n /= 2;
        p *= 10;
    }
    return b;
}

int main() {
    // int decNum = 5;

    // int ans = 0;
    // int power = 1;

    // while (decNum > 0) {
    //     int rem = decNum % 2;
    //     decNum = decNum / 2;
    //     ans = rem * power;
    //     power *= 10;
    // }

    // cout << "Converted Binary number: " << ans << "\n";
    // int num = 5;
    // int bin = dec_to_bin(num);
    // cout << "Binary of " << num << " is " << bin << "\n";
    cout << "decimal\t" << "binary";
    for (int i = 1; i <= 10; i++) {
        cout << i << "\t" << dec_to_bin(i) << "\n";
    }
    cout << "\n\n";

    return 0;
}