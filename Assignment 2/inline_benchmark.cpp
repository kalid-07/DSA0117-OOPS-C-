#include <iostream>
#include <chrono>
using namespace std;
constexpr int N = 10000000;

int normalAdd(int a, int b) { return a + b; }
inline int inlineAdd(int a, int b) { return a + b; }

int main() {
    volatile long long sink = 0; // prevents removal of the accumulated result
    auto start1 = chrono::steady_clock::now();
    for (int i = 0; i < N; ++i) sink += normalAdd(i, 1);
    auto end1 = chrono::steady_clock::now();
    auto start2 = chrono::steady_clock::now();
    for (int i = 0; i < N; ++i) sink += inlineAdd(i, 1);
    auto end2 = chrono::steady_clock::now();
    cout << "Calls per function: " << N << '\n';
    cout << "Normal function: "
         << chrono::duration_cast<chrono::microseconds>(end1-start1).count() << " us\n";
    cout << "Inline function: "
         << chrono::duration_cast<chrono::microseconds>(end2-start2).count() << " us\n";
    cout << "Result guard: " << sink << '\n';
}
