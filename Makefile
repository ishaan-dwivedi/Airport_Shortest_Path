all: airport test

airport: main.o graph.o 
	g++ graph.o main.o -o airport

test: tests.o catch.o graph.o
	g++ tests.o catchmain.o graph.o -o test

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

graph.o: graph.cpp
	g++ -std=c++11 -c graph.cpp

tests.o: ./tests/tests.cpp
	g++ -std=c++11 -c ./tests/tests.cpp

catch.o: ./catch/catchmain.cpp
	g++ -std=c++11 -c ./catch/catchmain.cpp 

clean: 
	rm *.o airport