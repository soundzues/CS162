all: program

program: list.o main.o supplied.o
	g++ -Wall -g list.o main.o supplied.o -o program
list.o: list.cpp
	g++ -Wall -c -g list.cpp -o list.o
main.o: main.cpp
	g++ -Wall -c -g main.cpp -o main.o
clean:
	rm main.o list.o
