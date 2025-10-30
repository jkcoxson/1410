// Jackson Coxson

#include "Account.hpp"

class CheckingAccount : public Account {
    int check_count = 0; // how many checks since last update

  public:
    CheckingAccount(int num, string name, float bal, float fee)
        : Account(num, std::move(name), bal, fee) {}

    void update() override {
        // Deduct accumulated check fees
        float total_fee = check_count * interest; // fee per check
        balance -= total_fee;
        check_count = 0;
    }

    void transaction(float trans) override {
        if (trans >= 0) {
            // Deposit
            balance += trans;
        } else {
            float withdrawal = -trans;

            if (withdrawal > balance) {
                // Bounced check
                balance -= (25.0f + interest);
                // withdrawal is rejected
            } else {
                // Regular check withdrawal
                balance -= withdrawal;
                check_count++;
            }
        }
    }
};
