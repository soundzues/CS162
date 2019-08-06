all: program

program: functions.o main.o
	g++ -g -Wall functions.o main.o -o program
functions.o: functions.cpp
	g++ -g -c -Wall functions.cpp
main.o: main.cpp
	g++ -g -c -Wall main.cpp
clean:
	rm functions.o main.o
