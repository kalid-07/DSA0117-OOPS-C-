#include <iostream>
using namespace std;

struct Parcel { double weightKg; bool express; bool insured; };

// Distinct parameter types avoid ambiguous overloads.
double charge(int weightGrams, bool express = false, bool insured = false) {
    double kg = weightGrams / 1000.0;
    return kg * 40.0 + (express ? 50.0 : 0.0) + (insured ? 20.0 : 0.0);
}
double charge(double weightKg, bool express = false, bool insured = false) {
    return weightKg * 40.0 + (express ? 50.0 : 0.0) + (insured ? 20.0 : 0.0);
}
double charge(float weightKg) { return static_cast<double>(weightKg) * 40.0; }
double charge(const Parcel& p) {
    return p.weightKg * 40.0 + (p.express ? 50.0 : 0.0) + (p.insured ? 20.0 : 0.0);
}

int main() {
    cout << "charge(2)       = " << charge(2) << '\n';
    cout << "charge(2.0)     = " << charge(2.0) << '\n';
    cout << "charge(2.0f)    = " << charge(2.0f) << '\n';
    cout << "charge(2000, true) = " << charge(2000, true) << '\n';
    cout << "charge(2.5, true, true) = " << charge(2.5, true, true) << '\n';
    Parcel p{3.0, false, true};
    cout << "charge(Parcel)  = " << charge(p) << '\n';
}
