CXXFLAGS=-std=c++11 
CXX=g++

all: Sorts.hpp
	${CXX} ${CXXFLAGS} -c gtest-all.cpp
	${CXX} ${CXXFLAGS} -o Sort10 test.cpp gtest-all.o


clean:
	rm -f Sort10 *.o
