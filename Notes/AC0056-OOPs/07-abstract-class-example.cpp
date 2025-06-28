#include <iostream>
using namespace std;

class Shape {
    virtual void draw() = 0;  // pure virtual function by 0 being assigned -> Class became abstract
};

class Triangle : public Shape {
   public:
    void draw() {
        cout << endl
             << "Drawing a triangle\n"
             << endl;
    }
};

int main() {
    // Shape s1;

    Triangle t1;

    t1.draw();

    return 0;
}
