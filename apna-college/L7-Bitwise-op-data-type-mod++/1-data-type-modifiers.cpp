#include <iostream>
using namespace std;

int main() {
    cout << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long int) << endl; // Ensure >= 4 in all system new and old
    cout << sizeof(short int) << endl;
    cout << sizeof(long long int) << endl; // or long long
    // cout << sizeof(long long) << endl;

    return 0;
}