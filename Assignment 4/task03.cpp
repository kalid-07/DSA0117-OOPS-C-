#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;
    int pin;
public:
    Address(const string& c, int p) : city(c), pin(p) {}
    string str() const { return city + "-" + to_string(pin); }
};

class Person {
protected:
    string name;
    int age;
    Address home;
public:
    Person(const string& n, int a, const string& city, int pin)
        : name(n), age(a), home(city, pin) {}
};

class Course {
    string courseName;
public:
    Course(const string& c) : courseName(c) {}
    string getName() const { return courseName; }
};

class Student : public Person {
    long long regNo;
    Course course;
public:
    Student(const string& n, int a, long long r, const string& city,
            int pin, const string& c)
        : Person(n, a, city, pin), regNo(r), course(c) {}
    void print() const {
        cout << regNo << " " << name << " (" << age << ") "
             << home.str() << " " << course.getName() << '\n';
    }
};

int main() {
    Student s("Kavya", 19, 192311001, "Salem", 636001, "C++");
    s.print();
}