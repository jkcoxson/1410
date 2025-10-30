#ifndef BANK_HPP
#define BANK_HPP
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Account.hpp" // ONLY BARE minimum skeleton provided

// CREATE these files ...
#include "Checking.hpp"
#include "Loan.hpp"
#include "Savings.hpp"

// FEEL FREE to ADD/DELETE Anything, but make sure it does not fail compilation of UNMODIFIED
// test.cpp
class Bank {
  private:
    int      accounts = 0; // starts with no accounts
    Account* head     = nullptr;
    Account* tail     = nullptr;

  public:
    Bank() : accounts(0) {} // Constructor

    ~Bank() {
        Account* curr = head;
        while (curr) {
            Account* next = curr->getNext();
            delete curr;
            curr = next;
        }
    }

    void account(char f_letter, int acc_number, string acc_name, float balance, float interest) {
        Account* new_acc = nullptr;
        if (f_letter == 's') {
            new_acc = new SavingsAccount(acc_number, acc_name, balance, interest);
        } else if (f_letter == 'c') {
            new_acc = new CheckingAccount(acc_number, acc_name, balance, interest);
        } else if (f_letter == 'l') {
            new_acc = new LoanAccount(acc_number, acc_name, balance, interest);
        } else {
            return; // unknown account type
        }

        if (!head) {
            head = tail = new_acc;
        } else {
            tail->setNext(new_acc);
            tail = new_acc;
        }

        accounts++;
    }

    // processes the input file text
    int process(string line) {
        std::vector<std::string> args;
        std::stringstream        ss(line);
        std::string              arg;

        while (ss >> arg) {
            args.push_back(arg);
        }

        if (args.size() < 2) {
            // all commands need at least 2
            // panic
            std::cout << "Your command doesn't have enough arguments ya dummy" << std::endl;
            std::abort();
        }

        // switch on the command type
        std::string command = args[0];

        if (command == "s" || command == "c" || command == "l") {
            // Create a new savings account. An account number, a name, an initial balance, and the
            // interest rate are supplied.
            // Create a new checking account. An account number, a name, an initial balance, and
            // the fee for each processed check are supplied.
            // Create a new loan account. An account number, a name, an initial balance, and the
            // interest rate are supplied.

            if (args.size() < 5) {
                std::cout << "Your command doesn't have enough arguments for 's' ya dummy"
                          << std::endl;
                std::abort();
            }

            int         account_number = std::stoi(args[1]); // I sure hope nothing bad happens
            std::string account_name   = args[2];
            float       init           = std::stof(args[3]);
            float       interest       = std::stof(args[4]);
            account(command[0], account_number, account_name, init, interest);
        } else if (command == "t") {
            // Perform a transaction. An account number and the amount of the transaction are
            // supplied.
            // o For savings accounts, a positive value is a deposit and a negative value is a
            // withdrawal.
            // o For checking accounts, a positive value is a deposit and a negative value
            // represents a check.
            // o For loan accounts, a positive value represents a payment on the loan and a
            // negative value represents the borrowing of additional money.
            if (args.size() < 3) {
                cout << "Transaction command missing args" << endl;
                std::abort();
            }

            int      acc_num = std::stoi(args[1]);
            float    amount  = std::stof(args[2]);

            Account* acc     = findNumber(acc_num);
            if (!acc) {
                cout << "Account not found: " << acc_num << endl;
                return -1;
            }

            acc->transaction(amount);
        } else if (command == "u") {
            // Perform an update. An account number is supplied.
            //
            // o For savings accounts, calculate and add interest earned.
            // o For checking accounts, calculate and deduct the fee for each check.
            // o For loan accounts, calculate and add the interest charged to the outstanding
            // loan balance.
            if (args.size() < 2) {
                cout << "Update command missing account number" << endl;
                std::abort();
            }

            int      acc_num = std::stoi(args[1]);
            Account* acc     = findNumber(acc_num);
            if (!acc) {
                cout << "Account not found: " << acc_num << endl;
                return -1;
            }

            acc->update();
        } else {
            std::cout << "unknown command: " << command << " - you messed up" << std::endl;
            std::abort();
        }

        return 0;
    }

    Account* findNumber(int acc_num) {
        Account* curr = head;
        while (curr) {
            if (curr->getAccNum() == acc_num) {
                return curr;
            }
            curr = curr->getNext();
        }
        return nullptr;
    }

    int      getCount() { return accounts; }

    // Provided for YOU :-)
    Account* operator[](int acc_num) {
        return findNumber(acc_num); // overloads the [] operator to find the account
    }

    // ADD any other functions you deem necessary
};

// ALL IMPLEMENTATION Goes Here

#endif
