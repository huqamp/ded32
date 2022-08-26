all: hello

hello: main.o other.o equation.o testing.o
	g++ main.o other.o equation.o testing.o -o auf

main.o: main.cpp
	g++ -c main.cpp

equation.o: equation.cpp
	g++ -c equation.cpp

other.o: other.cpp
	g++ -c other.cpp

testing.o: testing.cpp
	g++ -c testing.cpp