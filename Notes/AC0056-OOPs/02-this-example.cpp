
#include <iostream>
#include <string>
using namespace std;

class Teacher {
   private:
    double salary;

   public:
    string name;
    Teacher(string name, double salary) {
        this->name = name;
        this->salary = salary;
    }

    void printData() {
        cout << "Teacher name: " << this->name << endl;
        cout << "Teacher salary: " << this->salary << endl;
    }
};

int main() {
    Teacher t1("Tony Stark", 50000);

    t1.printData();

    return 0;
}