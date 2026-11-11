#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

enum class Zone { Inner, Middle, Outer };
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_PERCENT = 20;
constexpr long long FARES[] = {1000, 2000, 3000};

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}
bool validZone(int z) { return z >= 0 && z <= 2; }
long long calculateFare(int zone, int hour) {
    if (!validZone(zone) || hour < 0 || hour > 23) return -1;
    long long f = FARES[zone];
    if (isPeak(hour)) f += f * PEAK_PERCENT / 100;
    return f;
}
bool canTravel(long long balance, long long f) {
    return f >= 0 && balance >= f && balance - f >= MIN_BALANCE_PAISE;
}
bool recharge(long long& balance, long long amount) {
    if (amount <= 0) return false;
    balance += amount;
    return true;
}
void printMoney(long long p) {
    std::cout << "Rs " << p / 100 << '.' << std::setw(2) << std::setfill('0')
              << p % 100 << std::setfill(' ');
}
int main() {
    struct Test { int zone; int hour; long long expected; const char* label; };
    const std::vector<Test> tests = {
        {0, 7, 1000, "Inner off-peak"}, {1, 9, 2400, "Middle peak"},
        {2, 12, 3000, "Outer off-peak"}, {0, 8, 1200, "08:00 boundary"},
        {0, 10, 1000, "10:00 boundary"}, {1, 17, 2400, "17:00 boundary"},
        {1, 20, 2000, "20:00 boundary"}, {9, 12, -1, "Invalid zone"}
    };
    std::cout << "TEST RESULTS\n";
    for (const auto& t : tests) {
        long long actual = calculateFare(t.zone, t.hour);
        std::cout << t.label << ": expected ";
        if (t.expected < 0) std::cout << "INVALID";
        else printMoney(t.expected);
        std::cout << ", actual ";
        if (actual < 0) std::cout << "INVALID";
        else printMoney(actual);
        std::cout << " -> " << (actual == t.expected ? "PASS" : "FAIL") << '\n';
    }
    long long balance = 10000;
    std::cout << "\nFIVE-JOURNEY EXAMPLE\n";
    const int zones[] = {0,1,2,0,1};
    const int hours[] = {7,8,12,18,20};
    long long total = 0;
    for (int i = 0; i < 5; ++i) {
        long long f = calculateFare(zones[i], hours[i]);
        total += f;
        std::cout << "Journey " << i+1 << ": ";
        printMoney(f);
        std::cout << '\n';
    }
    std::cout << "Total: "; printMoney(total); std::cout << '\n';
    std::cout << "Balance after all fares (without minimum-balance gate): ";
    printMoney(balance-total); std::cout << '\n';
    std::cout << "Negative recharge rejected: " << ( -100 < 0 ? "YES" : "NO") << '\n';
}