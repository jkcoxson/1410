// Jackson Coxson

#include <iomanip>
#include <sstream>
#include <string>

class MyComplex {
public:
  MyComplex(float a, float b) {
    fr_part = a;
    imaginary_part = b;
  }

  // (x+yi)×(u+vi)=(xu−yv)+(xv+yu)i
  MyComplex operator*(const MyComplex &other) {
    float a =
        (fr_part * other.fr_part) - (imaginary_part * other.imaginary_part);
    float b =
        (fr_part * other.imaginary_part) + (imaginary_part * other.fr_part);
    return MyComplex(a, b);
  }
  MyComplex operator+(const MyComplex &other) {
    return MyComplex(fr_part + other.fr_part,
                     imaginary_part + other.imaginary_part);
  }
  MyComplex operator-(const MyComplex &other) {
    //
    return MyComplex(fr_part - other.fr_part,
                     imaginary_part - other.imaginary_part);
  }

  std::string printMyComplex() {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << fr_part;
    if (imaginary_part >= 0)
      oss << " + " << imaginary_part << "i";
    else
      oss << " - " << -imaginary_part << "i";
    return oss.str();
  }

private:
  float fr_part;
  float imaginary_part;
};
