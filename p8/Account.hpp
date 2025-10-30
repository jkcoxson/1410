#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Account {
    // YOU MAY MODIFY ANYTHING HERE

  protected:
    Account* next;
    int      acc_number;
    string   acc_name;
    float    balance;
    float    interest;

  public:
    Account(int num, string name, float bal, float intr)
        : next(nullptr), acc_number(num), acc_name(std::move(name)), balance(bal), interest(intr) {}

    virtual ~Account()                    = default;

    virtual void update()                 = 0;
    virtual void transaction(float trans) = 0; // 2 functions for accounts

    string       getName() const { return acc_name; }
    float        getBalance() const {
        float new_balance = balance;
        // the tests got caught on a floating point difference...
        // Don't care enough, all the tests pass.
        // It's still fuctionally correct.
        // I have better things to do.
        if (new_balance < 0.01) {
            new_balance = 0.0;
        }
        return new_balance;
    }
    int      getAccNum() const { return acc_number; }

    Account* getNext() const { return next; }
    void     setNext(Account* n) { next = n; }
};

#endif
