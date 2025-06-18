// Detect if a power of 2 or not w/o loop (print true or false)
// https://www.geeksforgeeks.org/dsa/program-to-find-whether-a-given-number-is-power-of-2/
#include <iostream>
using namespace std;

/*
ip
    int num: a given number

op
    bool yes/no: if power of two or not

approach
    Using the property that the for powers of 2, n-1 has all the bits right of the number as 1's (1 for 2, 3 for 4, 7 for 8 and so on)

    Number taken & with num -1 will have all bits set to 0, so it will be 0 (check this)
    Number taken AND with *not of num - 1* (all to the right of number 0) will be equal to number itself
---
T&S

*/

int main() {
    // Using loop
    int num = 2;
    cout << ((num & (num - 1)) == 0) << endl;
    // cout << ((num & ((num - 1))) == 0) << endl;
    cout << (((num & (~(num - 1)))) == num) << endl;

    return 0;
}