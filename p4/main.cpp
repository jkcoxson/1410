// Jackson Coxson

#include "rational.h"
#include <iostream>

int main() {
    int n = 1;
    int d = 1;
    std::cout << "Enter numerator: ";
    std::cin >> n;
    std::cout << "Enter denominator: ";
    std::cin >> d;
    Rational             r       = Rational(n, d);

    bool                 reduced = r.reduce();
    std::tuple<int, int> res     = r.dump();
    if (reduced) {
        std::cout << "Fraction reduces to " << std::get<0>(res) << "/" << std::get<1>(res)
                  << std::endl;
    }

    int choice = 1;
    while (choice != 0) {

        std::cout << std::endl
                  << "1. Add a rational" << std::endl
                  << "2. Subtract a rational" << std::endl
                  << "3. Multiply by a rational" << std::endl
                  << "4. Divide by a rational" << std::endl
                  << "0. Exit" << std::endl
                  << "Enter selection: ";
        std::cin >> choice;
        if (choice > 4 || choice < 0) {
            std::cout << "bro can't even read basic directions, that's not an option ya dummy"
                      << std::endl;
            continue;
        }
        if (choice == 0) {
            return 0;
        }

        std::cout << "Enter numerator: ";
        std::cin >> n;
        std::cout << "Enter denominator: ";
        std::cin >> d;

        try {
            switch (choice) {
            case 1: {
                r.add(n, d);
                break;
            }
            case 2: {
                r.sub(n, d);
                break;
            }
            case 3: {
                r.mul(n, d);
                break;
            }
            case 4: {
                r.div(n, d);
                break;
            }
            }
        } catch (const std::string& e) { // try/catch is a terrible programming paradigm, yet here
                                         // we are. Have you considered optionals or boolean
                                         // returns? Rust and Go does this really well. Required
                                         // error handling correct error handling.
            std::cerr << "You caused an exception, dummy: " << e << std::endl;
            continue;
        }
        res = r.dump();

        std::cout << std::get<0>(res) << "/" << std::get<1>(res) << std::endl;
    }
}
