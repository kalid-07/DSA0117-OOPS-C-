#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    double balance;
    string transactions[10];
    int count;
    void addTransaction(const string& text) {
        if (count < 10) transactions[count++] = text;
        else {
            for (int i = 1; i < 10; ++i) transactions[i - 1] = transactions[i];
            transactions[9] = text;
        }
    }
public:
    SavingsAccount(const string& number, double openingBalance)
        : accountNumber(number), balance(openingBalance), count(0) {
        addTransaction("Opening balance: " + to_string(openingBalance));
    }
    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement() const;
};

void SavingsAccount::deposit(double amount) {
    if (amount <= 0) { cout << "Invalid deposit\n"; return; }
    balance += amount;
    addTransaction("Deposit: " + to_string(amount));
}
void SavingsAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance) { cout << "Invalid/insufficient withdrawal\n"; return; }
    balance -= amount;
    addTransaction("Withdrawal: " + to_string(amount));
}
void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << " | Balance: " << balance << '\n';
    cout << "Last " << count << " transactions (oldest to newest):\n";
    for (int i = 0; i < count; ++i) cout << i + 1 << ". " << transactions[i] << '\n';
}

int main() {
    SavingsAccount account("SAV1001", 1000.0);
    for (int i = 1; i <= 11; ++i) account.deposit(i * 100.0);
    account.withdraw(250.0);
    account.miniStatement();
}
