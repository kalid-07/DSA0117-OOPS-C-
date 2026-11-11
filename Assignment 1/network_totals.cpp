#include <iostream>
#include <climits>
int main() {
    const long long farePaise = 3000;
    const long long counts[] = {20000, 500000, 3000000};
    for (long long n : counts) {
        long long total = n * farePaise;
        std::cout << n << " journeys: " << total << " paise (Rs "
                  << total / 100 << ")\n";
        std::cout << "Fits common signed int: "
                  << (total <= INT_MAX ? "YES" : "NO") << '\n';
    }
    std::cout << "INT_MAX=" << INT_MAX << '\n';
    std::cout << "Use long long for network totals; signed int overflow "
                 "must not be relied upon.\n";
}