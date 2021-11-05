CFLAGS = -g -Wall
CC = g++

all: main

main: main.o DoublyLinkedList.o
	$(CC) $(CFLAGS) main.o DoublyLinkedList.o -o main

main.o : main.cpp
	$(CC) -c main.cpp

DoubleLinkedList.o : DoublyLinkedList.cpp DoublyLinkedList.h
	$(CC) -c DoublyLinkedList.cpp

clean:
	-rm -f core *.o
	-rm -f *.class
	-rm -f main
