# Makefile for lab 4.
all: program

program: app.o player.o
	g++ -g -Wall app.o player.o -o program
player.o: player.cpp
	g++ -g -c player.cpp
app.o: app.cpp
	g++ -g -c app.cpp
clean:
	rm player.o app.o
