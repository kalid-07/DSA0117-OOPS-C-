#include <iostream>
#include <array>
#include <string>
enum class Zone { Inner, Middle, Outer, Airport };
constexpr std::array<long long, 4> BASE = {1000, 2000, 3000, 6000};
constexpr long long MIN_BALANCE = 5000;

class Pass {
    bool active;
    bool zoneAllowed[4];
public:
    Pass(bool enabled, int firstZone, int secondZone)
        : active(enabled), zoneAllowed{false,false,false,false} {
        if (firstZone >= 0 && firstZone < 4) zoneAllowed[firstZone] = true;
        if (secondZone >= 0 && secondZone < 4) zoneAllowed[secondZone] = true;
    }
    bool covers(int zone) const {
        return active && zone >= 0 && zone < 4 && zoneAllowed[zone];
    }
};
class SmartCard {
    long long balancePaise;
public:
    explicit SmartCard(long long initial) : balancePaise(initial < 0 ? 0 : initial) {}
    bool canPay(long long fare) const {
        return fare >= 0 && balancePaise - fare >= MIN_BALANCE;
    }
    bool deduct(long long fare) {
        if (!canPay(fare)) return false;
        balancePaise -= fare;
        return true;
    }
    long long balance() const { return balancePaise; }
};
long long fare(int zone, bool peak, bool weekend, const Pass& pass) {
    if (zone < 0 || zone > 3) return -1;
    if (pass.covers(zone)) return 0;
    long long amount = BASE[zone];
    if (weekend) amount -= amount * 10 / 100; // weekend discount replaces peak surcharge
    else if (peak) amount += amount * 20 / 100;
    return amount;
}
int main() {
    Pass monthly(true, 0, 2); // Inner and Outer zones
    SmartCard card(20000);
    struct Journey { int zone; bool peak; bool weekend; };
    Journey trips[] = {{0,true,false}, {1,true,false}, {3,false,true}, {2,false,false}};
    for (const auto& t : trips) {
        long long f = fare(t.zone, t.peak, t.weekend, monthly);
        if (f < 0) { std::cout << "Invalid zone\n"; continue; }
        if (f == 0) { std::cout << "Monthly pass: free journey in covered zone\n"; continue; }
        if (card.deduct(f)) std::cout << "Fare paid: " << f << " paise; balance: " << card.balance() << '\n';
        else std::cout << "Denied: minimum balance rule\n";
    }
}