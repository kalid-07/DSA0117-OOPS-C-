#include <iostream>
enum class Zone { Inner, Middle, Outer };
constexpr long long INNER_FARE = 1000;
constexpr long long MIDDLE_FARE = 2000;
constexpr long long OUTER_FARE = 3000;
constexpr int PEAK_PERCENT = 20;
constexpr long long MIN_BALANCE = 5000;
int main() {
    std::cout << "Fares (paise): " << INNER_FARE << ' '
              << MIDDLE_FARE << ' ' << OUTER_FARE << '\n';
    std::cout << "Peak surcharge: " << PEAK_PERCENT << "%\n";
    std::cout << "Minimum balance (paise): " << MIN_BALANCE << '\n';
    Zone selected = Zone::Middle;
    std::cout << "Zone enum class safely stores a named zone.\n";
    (void)selected;
}