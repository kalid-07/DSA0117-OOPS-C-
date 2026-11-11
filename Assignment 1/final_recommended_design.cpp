#include <iostream>
#include <array>
enum class Zone { Inner, Middle, Outer };
constexpr std::array<long long, 3> BASE_FARE = {1000, 2000, 3000};
constexpr int PEAK_PERCENT = 20;
constexpr long long MIN_BALANCE = 5000;
bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}
long long calculateFare(Zone zone, int hour) {
    int index = static_cast<int>(zone);
    if (index < 0 || index >= static_cast<int>(BASE_FARE.size())
        || hour < 0 || hour > 23) return -1;
    long long fare = BASE_FARE[static_cast<std::size_t>(index)];
    if (isPeak(hour)) fare += fare * PEAK_PERCENT / 100;
    return fare;
}
class SmartCard {
    long long balancePaise;
public:
    explicit SmartCard(long long initial) : balancePaise(initial < 0 ? 0 : initial) {}
    bool pay(long long fare) {
        if (fare < 0 || balancePaise - fare < MIN_BALANCE) return false;
        balancePaise -= fare;
        return true;
    }
    long long balance() const { return balancePaise; }
};
int main() {
    SmartCard card(10000);
    const Zone zones[] = {Zone::Inner, Zone::Outer, Zone::Middle};
    const int hours[] = {7, 18, 20};
    for (int i = 0; i < 3; ++i) {
        long long fare = calculateFare(zones[i], hours[i]);
        if (card.pay(fare))
            std::cout << "Accepted fare=" << fare
                      << " paise; balance=" << card.balance() << '\n';
        else
            std::cout << "Denied; balance=" << card.balance() << '\n';
    }
}