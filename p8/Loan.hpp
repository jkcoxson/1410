// Jackson Coxson

#include "Account.hpp"

class LoanAccount : public Account {
  public:
    LoanAccount(int num, string name, float bal, float intr)
        : Account(num, std::move(name), bal, intr) {}

    void update() override {
        balance += balance * interest; // charge interest
    }

    void transaction(float trans) override {
        if (trans > 0) {
            // Payment
            balance -= trans;
        } else {
            // Borrow more
            balance -= trans; // minus negative = add
        }
    }
};
