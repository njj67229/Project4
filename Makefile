CFLAGS = -g -Wall -Wreturn-type
CC = g++

all: main

main: main.o BinaryTree.o
	$(CC) $(CFLAGS) main.o BinaryTree.o -o main

main.o : main.cpp
	$(CC) -c main.cpp

BinaryTree.o : BinaryTree.cpp BinaryTree.h
	$(CC) -c BinaryTree.cpp

clean:
	-rm -f core *.o
	-rm -f *.class
	-rm -f main
