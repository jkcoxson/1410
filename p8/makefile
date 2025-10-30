all: Bank.hpp Account.hpp Checking.hpp Savings.hpp Loan.hpp 
	g++ -c gtest-all.cpp
	g++ -o BankSW test.cpp gtest-all.o


clean:
	rm -rf BankSW gtest-all.o

