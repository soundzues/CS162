all: program

program: implementation.o main.o
	g++ -Wall -g implementation.o main.o -o program

implementation.o: implementation.cpp
	g++ -g -c implementation.cpp

main.o: main.cpp
	g++ -g -c main.cpp

debug:
	gdb -tui ./program

valgrind:
	valgrind --tool=memcheck --leak-check=full ./program

test:
	./program

clean:
	rm implementation.o main.o
