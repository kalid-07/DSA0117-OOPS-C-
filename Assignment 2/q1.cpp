#include <iostream>
using namespace std;

void change(int a, int& b, int* c) {
    a += 10;       // local copy only
    b += 10;       // changes caller's b
    *c += 10;      // changes caller's c through pointer
}

int& bigger(int& p, int& q) { return p > q ? p : q; }
void show(int x, int y = 5, int z = 10) { cout << x + y + z << ' '; }

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}
void applyConcession(long long& fee, int percent) {
    fee -= fee * percent / 100;
}
void applyConcessionPointer(long long* fee, int percent) {
    if (fee != nullptr) *fee -= *fee * percent / 100;
}
long long concessionReturn(long long fee, int percent) {
    return fee - fee * percent / 100;
}

int main() {
    int a = 1, b = 2, c = 3;
    change(a, b, &c);
    cout << a << ' ' << b << ' ' << c << '\n';
    bigger(a, c) = 100;
    cout << a << ' ' << c << '\n';
    show(1); show(1, 2); show(1, 2, 3); cout << '\n';

    long long hostelFee = 45000;
    applyByValue(hostelFee, 10);
    cout << "after call by value   : " << hostelFee << '\n';
    applyConcession(hostelFee, 10);
    cout << "after call by reference: " << hostelFee << '\n';
    long long pointerFee = 45000;
    applyConcessionPointer(&pointerFee, 15);
    cout << "after call by pointer : " << pointerFee << '\n';
    cout << "returned fee (25%): " << concessionReturn(45000, 25) << '\n';
}
