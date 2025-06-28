#include <iostream>
using namespace std;

class Base {
   public:
    void nonVirtualFunction() {
        cout << "Base non-virtual function\n";
    }

    virtual void virtualFunction() {
        cout << "Base virtual function\n";
    }
};

class Derived : public Base {
   public:
    void nonVirtualFunction() {
        cout << "Derived non-virtual function\n";
    }

    void virtualFunction() override {
        cout << "Derived virtual function\n";
    }
};

int main() {
    Base* ptr = new Derived();  // Upcasting Derived contains a full Base and some other things so it makes some sense
                                // Virtual functions take care of function overloading at runtime
                                // Cannot access Base only functions

    ptr->nonVirtualFunction();  // Compile-time binding
    ptr->virtualFunction();     // Runtime binding

    // delete ptr;
    return 0;
}
