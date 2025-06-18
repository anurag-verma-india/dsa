// A function to reverse an integer

#include <iostream>
using namespace std;

int main() {
    int num = 125;

    // Print

    // while (num > 0) {
    //     cout << (num % 10);
    //     num /= 10;
    // }

    // Create a new variable
    // int pow = 1;
    int rev = 0;
    while (num > 0) {
        int rem = num % 10;
        // rev += rev * pow;
        // pow *= 10;
        rev = rev * 10 + rem;
        num /= 10;
    }

    cout << endl;
    cout << rev << endl;

    return 0;
}