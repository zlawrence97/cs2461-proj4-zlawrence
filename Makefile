SOURCES=hashTable.c LinkedList.c
CFLAGS=-g -Wall

all:
	gcc $(SOURCES) $(CFLAGS)