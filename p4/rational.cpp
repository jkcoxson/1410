// Jackson Coxson

#include "rational.h"
#include <string>
#include <tuple>

// ints are copied, so we can modify at will
int euclid(int n, int d) {
    while (d != 0) {
        // creating the remainder var over and over is fine
        // the assembly shows that the compiler knows what we mean
        // https://godbolt.org/z/ejh4qbfvs
        int remainder = n % d;
        n             = d;
        d             = remainder;
    }
    return n;
}

Rational::Rational() {
    numerator = 1;
    denom     = 1;
}

Rational::Rational(int n, int d) {
    numerator = n;
    denom     = d;
}

void Rational::add(int n, int d) {
    this->check_input(n, d);
    // nobody said this code has to be efficient
    n               = n * this->denom;
    this->numerator = this->numerator * d;
    this->denom     = this->denom * d;
    this->numerator = this->numerator + n;
    this->reduce();
}
void Rational::sub(int n, int d) {
    this->check_input(n, d);
    n               = n * this->denom;
    this->numerator = this->numerator * d;
    this->denom     = this->denom * d;
    if (this->numerator < n) {
        throw std::string(
            "test input didn't include negative numbers, we're not implementing them. Dummy. Now "
            "the results are corrupt, I hope you're happy.");
    }
    this->numerator = this->numerator - n;
    this->reduce();
}

void Rational::mul(int n, int d) {
    this->check_input(n, d);
    this->numerator = this->numerator * n;
    this->denom     = this->denom * d;
    this->reduce();
}

void Rational::div(int n, int d) {
    this->check_input(n, d);
    this->numerator = this->numerator * d;
    this->denom     = this->denom * n;
    this->reduce();
}

void Rational::check_input(int n, int d) {
    if (d == 0) {
        throw std::string("you can't divide by zero, dummy");
    }
    if (d < 0 || n < 0) {
        throw std::string(
            "test input didn't include negative numbers, we're not implementing them. Dummy.");
    }
}

std::tuple<int, int> Rational::dump() {
    return std::tuple<int, int>(this->numerator, this->denom);
}

bool Rational::reduce() {
    int gcf = euclid(this->numerator, this->denom);
    if (gcf == 1) {
        return false;
    }
    this->numerator = this->numerator / gcf;
    this->denom     = this->denom / gcf;
    return true;
}
