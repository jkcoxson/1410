// Jackson Coxson

#include "Account.hpp"

class SavingsAccount : public Account {
  public:
    SavingsAccount(int num, string name, float bal, float intr)
        : Account(num, std::move(name), bal, intr) {}

    void update() override {
        balance += balance * interest; // interest is given as rate
    }

    void transaction(float trans) override {
        // Deposit
        if (trans >= 0) {
            balance += trans;
        }
        // Withdrawal
        else if (balance + trans >= 0) {
            balance += trans;
        } else {
            cout << "Transaction rejected: insufficient funds for " << acc_name << endl;
        }
    }
};
