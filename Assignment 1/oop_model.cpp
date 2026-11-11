#include <iostream>
#include <string>
enum class Zone { Inner, Middle, Outer };
class FareTable {
public:
    static constexpr long long fares[] = {1000, 2000, 3000};
    static constexpr long long minimumBalance = 5000;
    long long getFare(Zone z) const {
        switch (z) {
            case Zone::Inner: return fares[0];
            case Zone::Middle: return fares[1];
            case Zone::Outer: return fares[2];
        }
        return -1;
    }
};
constexpr long long FareTable::fares[];
class SmartCard {
    std::string cardId;
    long long balancePaise;
public:
    SmartCard(std::string id, long long balance)
        : cardId(std::move(id)), balancePaise(balance < 0 ? 0 : balance) {}
    bool canTravel(long long fare) const {
        return fare >= 0 && balancePaise - fare >= FareTable::minimumBalance;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balancePaise -= fare;
        return true;
    }
    long long balance() const { return balancePaise; }
};
int main() {
    FareTable table;
    SmartCard card("CARD001", 10000);
    long long f = table.getFare(Zone::Outer);
    std::cout << "Outer fare paise: " << f << '\n';
    std::cout << "Journey accepted: " << (card.deduct(f) ? "YES" : "NO") << '\n';
    std::cout << "Balance paise: " << card.balance() << '\n';
}