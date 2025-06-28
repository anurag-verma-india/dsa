#include <iostream>
using namespace std;

class Student {
   private:
    string name;
    double *cgpaPtr;  // Pointer to memory (will be needed to use dynamic memory allocation)

   public:
    // constructor
    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;  // Dynamically allocated new memory in heap
        *cgpaPtr = cgpa;
    }

    // destructor
    ~Student() {
        delete cgpaPtr;  // Freed memory when the object goes out of scope (when destructor is called
        // Prevented memory leak
    }

    // Getter
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main() {
    Student s1 = Student("Anurag", 8.5);

    s1.getInfo();

    return 0;
}
