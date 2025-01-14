
// https://www.geeksforgeeks.org/cpp-functions-pass-by-reference/

// C++ program to implement
// pass-by-reference
#include <iostream>
using namespace std;

void f(int& x) {
    x--;
}

// Driver code
int main() {
    int a = 5;
    cout << a << endl;
    f(a);
    cout << a << endl;
}
