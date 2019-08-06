all: program

program: main.o implementation.o
	g++ -Wall -g main.o implementation.o -o program

main.o: main.cpp
	g++ -g -c main.cpp


implementation.o: implementation.cpp
	g++ -g -c implementation.cpp

clean:
	rm main.o implementation.o


