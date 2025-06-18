// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
i/p
    int bin: binary number

o/p
    int dec: decimal number

approach
    repeatedly multiply the position of the binary number by it's position to get it's place value (in decimal, since operations are in decimal)
    add the place value to the final number



T&S Cplxity

*/

int binToDec(int bin) {
    int dec = 0;
    int pow = 1;
    while (bin > 0) {
        int rem = bin % 2;
        dec += rem * pow;
        bin /= 10;
        pow *= 2;
    }
    return dec;
}

int main() {
    cout << "Binary of " << 1010 << " is " << binToDec(1010) << "\n";
    return 0;
}