// Jackson Coxson

#include <tuple>

class Rational {
  public:
    Rational();
    Rational(int n, int d);
    void                 add(int n, int d);
    void                 sub(int n, int d);
    void                 mul(int n, int d);
    void                 div(int n, int d);
    std::tuple<int, int> dump();
    bool                 reduce();

  private:
    void check_input(int n, int d);
    int  numerator;
    int  denom;
};
