#include <iostream>
#include <iomanip>
#include <limits>
int main() {
    int hour = -1;
    std::cout << "Enter journey hour (0-23): ";
    while (!(std::cin >> hour) || hour < 0 || hour > 23) {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Invalid hour. Enter a number from 0 to 23: ";
    }
    long long farePaise = 1200;
    std::cout << "Accepted hour: " << hour << '\n';
    std::cout << "Fare: Rs " << farePaise / 100 << '.'
              << std::setw(2) << std::setfill('0') << farePaise % 100 << '\n';
}