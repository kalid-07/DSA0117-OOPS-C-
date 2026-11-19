#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name, phone;
    int id;
public:
    Person(string n, int i, string p) : name(n), phone(p), id(i) {}
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;
public:
    Student(string n, int i, string p, string pr, double c)
        : Person(n, i, p), programme(pr), cgpa(c) {}
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;
public:
    Staff(string n, int i, string p, string d, double s)
        : Person(n, i, p), department(d), salary(s) {}
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p, string pr, double c,
                      string d, double s)
        : Person(n, i, p), Student(n, i, p, pr, c),
          Staff(n, i, p, d, s) {}
};

class ResearchScholar : public Student {
    double fellowship;
public:
    ResearchScholar(string n, int i, string p, string pr, double c, double f)
        : Person(n, i, p), Student(n, i, p, pr, c), fellowship(f) {}
};

int main() {
    TeachingAssistant ta("Arun", 101, "9876543210", "B.Tech", 8.5, "IT", 30000);
    ResearchScholar rs("Kumar", 102, "9876543211", "M.Tech", 9.0, 15000);
    cout << "Teaching Assistant and Research Scholar created successfully\n";
}