#include <iostream>
constexpr long long MIN_BALANCE = 5000;
bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= MIN_BALANCE;
}
bool proceduralDeduct(long long& balance, long long fare) {
    if (!proceduralCanTravel(balance, fare)) return false;
    balance -= fare;
    return true;
}
class SmartCard {
    long long balancePaise;
public:
    explicit SmartCard(long long b) : balancePaise(b < 0 ? 0 : b) {}
    bool canTravel(long long fare) const {
        return fare >= 0 && balancePaise - fare >= MIN_BALANCE;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balancePaise -= fare;
        return true;
    }
    long long balance() const { return balancePaise; }
};
int main() {
    long long proceduralBalance = 10000;
    std::cout << "Procedural accepted: "
              << (proceduralDeduct(proceduralBalance, 3000) ? "YES" : "NO")
              << ", balance=" << proceduralBalance << '\n';
    SmartCard card(10000);
    std::cout << "OOP accepted: " << (card.deduct(3000) ? "YES" : "NO")
              << ", balance=" << card.balance() << '\n';
}