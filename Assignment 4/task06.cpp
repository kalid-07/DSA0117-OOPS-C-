#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double dailyRate;
    bool rented = false;
public:
    Vehicle(string r, double rate) : regNo(r), dailyRate(rate) {}
    virtual double charge(int days) const = 0;
    virtual string type() const = 0;
    virtual double lateFee(int daysLate) const { return daysLate * dailyRate * 0.5; }
    virtual void rent() { rented = true; }
    virtual void giveBack() { rented = false; }
    virtual ~Vehicle() = default;
    bool isRented() const { return rented; }
    string registration() const { return regNo; }
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate) : Vehicle(r, rate) {}
    double charge(int days) const override { return dailyRate * days; }
    string type() const override { return "Bicycle"; }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelLevel;
    string serviceDue;
public:
    MotorVehicle(string r, double rate, double fuel, string due)
        : Vehicle(r, rate), fuelLevel(fuel), serviceDue(due) {}
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string r, double rate, double fuel, string due)
        : MotorVehicle(r, rate, fuel, due) {}
    double charge(int days) const override { return dailyRate * days; }
    string type() const override { return "Two-wheeler"; }
};

class Car : public MotorVehicle {
protected:
    int seats;
public:
    Car(string r, double rate, double fuel, string due, int s)
        : MotorVehicle(r, rate, fuel, due), seats(s) {}
    double charge(int days) const override { return dailyRate * days; }
    string type() const override { return "Car"; }
};

class ElectricCar : public Car {
    double batteryKWh;
    double ratePerKWh;
public:
    ElectricCar(string r, double rate, double fuel, string due, int seats,
                double battery, double kwhRate)
        : Car(r, rate, fuel, due, seats),
          batteryKWh(battery), ratePerKWh(kwhRate) {}
    double charge(int days) const override {
        return dailyRate * days + batteryKWh * ratePerKWh;
    }
    string type() const override { return "Electric car"; }
};

class ElectricBus : public MotorVehicle {
    int seats;
public:
    ElectricBus(string r, double rate, double fuel, string due, int s)
        : MotorVehicle(r, rate, fuel, due), seats(s) {}
    double charge(int days) const override { return dailyRate * days; }
    string type() const override { return "Electric bus"; }
};

int main() {
    vector<unique_ptr<Vehicle>> fleet;
    fleet.push_back(make_unique<Bicycle>("BIKE01", 100));
    fleet.push_back(make_unique<TwoWheeler>("TW01", 250, 80, "2026-12-01"));
    fleet.push_back(make_unique<Car>("CAR01", 1500, 70, "2026-12-10", 5));
    fleet.push_back(make_unique<ElectricCar>("EV01", 1800, 90, "2026-12-15", 5, 50, 8));
    fleet.push_back(make_unique<ElectricBus>("BUS01", 4000, 95, "2026-12-20", 30));

    for (auto& v : fleet) {
        v->rent();
        cout << v->type() << " " << v->registration()
             << " rented; charge for 2 days = " << v->charge(2) << '\n';
        v->giveBack();
        cout << "Returned; late fee (1 day late) = "
             << v->lateFee(1) << '\n';
    }
}