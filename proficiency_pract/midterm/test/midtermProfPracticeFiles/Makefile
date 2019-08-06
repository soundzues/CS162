all: program

program: array.o main.o supplied.o
	g++ -Wall -g array.o main.o supplied.o -o program

array.o: array.cpp
	g++ -g -c array.cpp

main.o: main.cpp
	g++ -g -c main.cpp
test: all 
	./program
clean:
	rm main.o array.o
