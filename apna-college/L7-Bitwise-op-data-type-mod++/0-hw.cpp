// Detect if a power of 2 or not w/o loop (print true or false)
// Doesn't work
#include <iostream>
using namespace std;

/*
ip
    int num: a given number

op
    bool yes/no: if power of two or not

approach
    XOR the given num with all possible powers of two
        (in each case if some value was found => which means some but was different in both of them since xor detects different values)
    Take & of all of them if even one of them is found to be 0 all will be 0 -> some power of 2 matched the value

---
T&S

*/

int main() {
    // Using loop
    int num = 2;
    int isNotAPower = true;
    int pow = 1;  // 2^0
    for (int i = 0; i < 32; i++) {
        // 0 to 31 all powers checking
        int xor_val = num ^ pow;
        isNotAPower &= xor_val;
    }

    if (!isNotAPower)
        cout << "Is a power of 2" << endl;
    else
        cout << "Is not a power of 2" << endl;

    // Using bits

    return 0;
}