#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>

class Bill {
protected:
    std::string patient;
public:
    explicit Bill(std::string p) : patient(std::move(p)) {}
    virtual ~Bill() = default;
    virtual double total() const = 0;
    virtual std::string type() const = 0;
};
class LaboratoryBill : public Bill {
    double tests, report;
public:
    LaboratoryBill(const std::string& p, double t, double r) : Bill(p), tests(t), report(r) {
        if (t < 0 || r < 0) throw std::invalid_argument("negative laboratory charge");
    }
    double total() const override { return tests + report; }
    std::string type() const override { return "LAB"; }
};
class Payer {
public:
    virtual ~Payer() = default;
    virtual double amountCovered(const Bill& b) const = 0;
};
class CorporatePayer : public Payer {
public:
    double amountCovered(const Bill& b) const override { return b.total() * 0.80; }
};
int main() {
    try {
        std::unique_ptr<Bill> bill = std::make_unique<LaboratoryBill>("Ravi", 2000, 500);
        CorporatePayer payer;
        std::cout << bill->type() << " total: " << bill->total() << '\n';
        std::cout << "Corporate covered: " << payer.amountCovered(*bill) << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Billing error: " << e.what() << '\n';
        return 1;
    }
}
