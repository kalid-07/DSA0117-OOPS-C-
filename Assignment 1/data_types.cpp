#include <iostream>
#include <climits>
#include <limits>
int main() {
    std::cout << "sizeof(bool)=" << sizeof(bool) << '\n';
    std::cout << "sizeof(char)=" << sizeof(char) << '\n';
    std::cout << "sizeof(int)=" << sizeof(int) << '\n';
    std::cout << "sizeof(long long)=" << sizeof(long long) << '\n';
    std::cout << "sizeof(float)=" << sizeof(float) << '\n';
    std::cout << "sizeof(double)=" << sizeof(double) << '\n';
    std::cout << "INT_MAX=" << INT_MAX << '\n';
    std::cout << "LLONG_MAX=" << LLONG_MAX << '\n';
    long long exactPaise = 1025 + 1025 + 1025;
    double approximateRupees = 10.25 + 10.25 + 10.25;
    std::cout << "Integer total paise=" << exactPaise << '\n';
    std::cout.precision(17);
    std::cout << "Double total rupees=" << approximateRupees << '\n';
    std::cout << "3,000,000 x 3,000 paise="
              << 3000000LL * 3000LL << " paise\n";
}