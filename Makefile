Airport: main.o graph.o
	g++ graph.o main.o -o Airport

main.o: main.cpp
	g++ -c main.cpp

graph.o: graph.cpp
	g++ -c graph.cpp

clean: 
	rm *.o Airport