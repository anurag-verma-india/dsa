#include <iostream>
using namespace std;

class A {
   public:
    A() {
        cout << "constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
};

int main() {
    if(true) {
        static A obj;
    }
    cout << "End of main function" << endl;
    return 0;
}

// constructor
// End of main function
// destructor