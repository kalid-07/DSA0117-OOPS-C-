#include <chrono>
#include <cstdint>
#include <iostream>
#include <variant>
#include <vector>

struct VirtualBill {
    virtual ~VirtualBill() = default;
    virtual double total() const = 0;
};
struct VOP : VirtualBill {
    double a, b; VOP(double x, double y) : a(x), b(y) {}
    double total() const override { return a + b; }
};
struct VIP : VirtualBill {
    double days, rate, surgery; VIP(double d, double r, double s) : days(d), rate(r), surgery(s) {}
    double total() const override { return days * rate + surgery; }
};
struct SwitchBill { int type; double a, b, c; };
double switchTotal(const SwitchBill& x) {
    switch (x.type) { case 0: return x.a + x.b; case 1: return x.a * x.b + x.c; default: return 0.0; }
}
struct OP { double a,b; double total() const { return a+b; } };
struct IP { double days,rate,surgery; double total() const { return days*rate+surgery; } };
using VariantBill = std::variant<OP,IP>;

template<class F> double measure(const char* label, F f) {
    const auto start = std::chrono::steady_clock::now();
    const double result = f();
    const auto stop = std::chrono::steady_clock::now();
    const auto ms = std::chrono::duration<double, std::milli>(stop-start).count();
    std::cout << label << ": total=" << result << ", ms=" << ms << '\n';
    return result;
}
int main() {
    constexpr std::size_t n = 1000000; // Increase to 10,000,000 for the larger test.
    std::vector<VirtualBill*> vp; std::vector<SwitchBill> sw; std::vector<VariantBill> vv;
    vp.reserve(n); sw.reserve(n); vv.reserve(n);
    for (std::size_t i=0;i<n;++i) {
        if (i%2==0) { vp.push_back(new VOP(500,1200)); sw.push_back({0,500,1200,0}); vv.emplace_back(OP{500,1200}); }
        else { vp.push_back(new VIP(3,2500,40000)); sw.push_back({1,3,2500,40000}); vv.emplace_back(IP{3,2500,40000}); }
    }
    const double a=measure("virtual", [&]{ double s=0; for(auto p:vp) s+=p->total(); return s; });
    const double b=measure("switch", [&]{ double s=0; for(const auto& x:sw) s+=switchTotal(x); return s; });
    const double c=measure("variant", [&]{ double s=0; for(const auto& x:vv) s+=std::visit([](const auto& v){return v.total();},x); return s; });
    std::cout << "results agree: " << ((a==b && b==c) ? "yes" : "no") << '\n';
    for (auto p:vp) delete p;
}
