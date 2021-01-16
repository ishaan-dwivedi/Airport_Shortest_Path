all: airport test

airport: main.o graph.o 
	g++ graph.o main.o -o airport

test: tests.o catch.o
	g++ tests.o catchmain.o -o test

main.o: main.cpp
	g++ -c main.cpp

graph.o: graph.cpp
	g++ -c graph.cpp

tests.o: ./tests/tests.cpp
	g++ -std=c++11 -c ./tests/tests.cpp

catch.o: ./catch/catchmain.cpp
	g++ -std=c++11 -c ./catch/catchmain.cpp 

clean: 
	rm *.o airport