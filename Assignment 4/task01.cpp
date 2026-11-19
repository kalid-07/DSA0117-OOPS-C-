#include <iostream>
#include <string>
using namespace std;

class Staff {
protected:
    string name;
    int id;
    double basic;
public:
    Staff(string n, int i, double b) : name(n), id(i), basic(b) {}
    virtual double pay() const = 0;
    virtual void display() const {
        cout << name << " " << id << " " << pay() << '\n';
    }
    virtual ~Staff() = default;
};

class Professor : public Staff {
    double research;
public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i, b), research(r) {}
    double pay() const override { return basic + basic * 0.42 + research; }
};

class LabAssistant : public Staff {
public:
    LabAssistant(string n, int i, double b) : Staff(n, i, b) {}
    double pay() const override { return basic + basic * 0.42; }
};

class GuestFaculty : public Staff {
    double hours, rate;
public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i, 0), hours(h), rate(r) {}
    double pay() const override { return hours * rate; }
};

int main() {
    Professor p("Arun", 101, 30000, 5000);
    LabAssistant l("Kumar", 102, 20000);
    GuestFaculty g("Ravi", 103, 20, 500);
    Staff* staff[] = {&p, &l, &g};
    for (const Staff* s : staff) s->display();
}