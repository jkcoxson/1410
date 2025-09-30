#include "gtest.h"

#include "MyComplex.hpp"

TEST(MyComplex, Add) {
  MyComplex a(5.1, 3.6);
  MyComplex b(34.1, 4.1);

  MyComplex c = a + b;

  std::string result = c.printMyComplex();

  EXPECT_EQ("39.2 + 7.7i", result);
}

TEST(MyComplex, AddNegatives1) {
  MyComplex a(-5.1, 3.6);
  MyComplex b(34.1, -4.1);

  MyComplex c = a + b;

  std::string result = c.printMyComplex();

  EXPECT_EQ("29.0 - 0.5i", result);
}

TEST(MyComplex, AddNegatives2) {
  MyComplex a(-5.1, -3.6);
  MyComplex b(2.1, 4.1);

  MyComplex c = a + b;

  std::string result = c.printMyComplex();

  EXPECT_EQ("-3.0 + 0.5i", result);
}

TEST(MyComplex, Subtract) {
  MyComplex a(5.6, 7.6);
  MyComplex b(4.2, 4.1);

  MyComplex c = a - b;

  std::string result = c.printMyComplex();

  EXPECT_EQ("1.4 + 3.5i", result);
}

TEST(MyComplex, SubtractNegatives) {
  MyComplex a(5.6, -7.6);
  MyComplex b(-4.2, 4.1);

  MyComplex c = a - b;

  std::string result = c.printMyComplex();

  EXPECT_EQ("9.8 - 11.7i", result);
}

TEST(MyComplex, Multiplication) {
  MyComplex a(1.0, -3.0);
  MyComplex b(2.0, 5.0);

  MyComplex c = a * b;

  std::string result = c.printMyComplex();

  EXPECT_EQ("17.0 - 1.0i", result);
}

TEST(MyComplex, MultiplicationNegatives) {
  MyComplex a(4.7, -3.4);
  MyComplex b(-2.9, 5.1);

  MyComplex c = a * b;

  std::string result = c.printMyComplex();

  EXPECT_EQ("3.7 + 33.8i", result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
