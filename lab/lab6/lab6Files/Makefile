all: program

program: app.o list.o
	g++ -Wall -g app.o list.o -o program
app.o: app.cpp
	g++ -c -Wall -g app.cpp -o app.o
list.o: list.cpp
	g++ -c -Wall -g list.cpp -o list.o
clean:
	rm list.o app.o
