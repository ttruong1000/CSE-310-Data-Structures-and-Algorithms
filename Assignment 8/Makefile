EXEC = assignment8
CC = g++
CFLAGS = -c -Wall

$(EXEC)	: Assignment8.o
	$(CC) -o $(EXEC) Assignment8.o

Assignment8.o	: Assignment8.cpp Graph.h LinkedList.h
	$(CC) $(CFLAGS) Assignment8.cpp

clean	:
	rm *.o