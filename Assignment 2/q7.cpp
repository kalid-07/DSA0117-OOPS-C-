#include <iostream>
#include <array>
#include <chrono>
using namespace std;
using Clock = chrono::steady_clock;
constexpr int K = 10;
constexpr int N = 2000000;

class ShiftHistory {
    array<int, K> data{};
public:
    void add(int value) {
        for (int i = 1; i < K; ++i) data[i - 1] = data[i];
        data[K - 1] = value;
    }
    long long checksum() const { long long s = 0; for (int x : data) s += x; return s; }
};
class CircularHistory {
    array<int, K> data{};
    int next = 0;
public:
    void add(int value) { data[next] = value; next = (next + 1) % K; }
    long long checksum() const { long long s = 0; for (int x : data) s += x; return s; }
};

template<class History>
long long benchmark() {
    History history;
    for (int i = 0; i < N; ++i) history.add(i);
    return history.checksum();
}
int main() {
    auto start1 = Clock::now();
    auto sum1 = benchmark<ShiftHistory>();
    auto end1 = Clock::now();
    auto start2 = Clock::now();
    auto sum2 = benchmark<CircularHistory>();
    auto end2 = Clock::now();
    auto ms1 = chrono::duration_cast<chrono::microseconds>(end1 - start1).count();
    auto ms2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();
    cout << "Operations per version: " << N << "\n";
    cout << "Shift-array checksum: " << sum1 << ", time: " << ms1 << " us\n";
    cout << "Circular-buffer checksum: " << sum2 << ", time: " << ms2 << " us\n";
    cout << "Both store the most recent " << K << " values; matching checksums: "
         << boolalpha << (sum1 == sum2) << '\n';
}
