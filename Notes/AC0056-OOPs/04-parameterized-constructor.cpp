#include <iostream>
using namespace std;

class Person {
   public:
    string name;
    int age;

    Person(string name, int age) {
        cout << "Parent class constructor called" << endl;
        this->name = name;
        this->age = age;
    }

    ~Person() {
        cout << "Parent class destructor called" << endl;
    }

    void getPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
    double cgpa;

   public:
    Student(string name, int age, double cgpa) : Person(name, age) { // Explicitly calling parameterized constructor of parent class
        cout << "Child class constructor called" << endl;
        this->cgpa = cgpa;
    }
    ~Student() {
        cout << "Child class destructor called" << endl;
    }
    void getStudent() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    Student s1("Anurag", 21, 8.5);
    s1.getStudent();
    return 0;
}