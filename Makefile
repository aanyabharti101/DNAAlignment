
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -g
LIBS = -lsfml-system

all: EDistance test EDistance.a

EDistance: main.o EDistance.o
	$(CXX) $(CXXFLAGS) -o EDistance main.o EDistance.o $(LIBS)

EDistance.a: EDistance.o
	ar rcs EDistance.a EDistance.o

test: test.o EDistance.o
	$(CXX) $(CXXFLAGS) -o test test.o EDistance.o

main.o: main.cpp EDistance.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

EDistance.o: EDistance.cpp EDistance.hpp
	$(CXX) $(CXXFLAGS) -c EDistance.cpp

test.o: test.cpp EDistance.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

clean:
	rm -f *.o EDistance test EDistance.a

lint:
	cpplint *.cpp *.hpp
	