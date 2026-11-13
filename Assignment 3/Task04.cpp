#include <iostream>
#include <iomanip>
using namespace std;
class Money {
    long long paise;
public:
    Money(long long rupees=0, int p=0) : paise(rupees*100+p) {}
    Money operator+(const Money& other) const { Money result; result.paise=paise+other.paise; return result; }
    Money operator-(const Money& other) const { Money result; result.paise=paise-other.paise; return result; }
    Money& operator+=(const Money& other) { paise+=other.paise; return *this; }
    bool operator==(const Money& other) const { return paise==other.paise; }
    bool operator<(const Money& other) const { return paise<other.paise; }
    friend ostream& operator<<(ostream& os,const Money& m) {
        long long a=m.paise; if(a<0) os << "-"; a = a<0 ? -a : a;
        return os << "Rs " << a/100 << '.' << setw(2) << setfill('0') << a%100 << setfill(' ');
    }
    friend istream& operator>>(istream& is, Money& m) { long long r; int p; if(is>>r>>p) m.paise=r*100+p; return is; }
};
int main() {
    Money a(120,75), b(79,25), c=a+b;
    cout << c << '\n' << boolalpha << (c==Money(200)) << '\n';
    cout << "Carry test: " << Money(0,75)+Money(0,50) << '\n';
    cout << "Negative test: " << Money(1,0)-Money(2,25) << '\n';
    a+=b; cout << "After +=: " << a << '\n';
}
