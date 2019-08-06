# Makefile for Lab 3, CS162 Summer '18
all: shoppingCart

shoppingCart: functions.o main.o
	g++ -g -Wall functions.o main.o -o shoppingCart

functions.o: functions.cpp
	g++ -g -c functions.cpp

main.o: main.cpp
	g++ -g -c main.cpp
test: all
	./shoppingCart

clean:
	rm main.o functions.o
