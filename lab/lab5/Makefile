# Makefile for lab 5.
all: lab5app

lab5app: app.o
	g++ -g app.o -o lab5app
app.o: app.cpp
	g++ -c -g -Wall app.cpp -o app.o
test:
	./lab5app
clean:
	rm app.o
