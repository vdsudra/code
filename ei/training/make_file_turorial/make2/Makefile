# Make using macro
# Here Header file is as <myMath.h> So use include
CC = gcc

INCLUDE = .

CFLAGS = -Wall

all: addDemo.o add.o sub.o
	$(CC) $(CFLAGS) -o demo addDemo.o add.o sub.o
addDemo.o: addDemo.c 
	$(CC) -I$(INCLUDE) -c addDemo.c
add.o: add.c
	$(CC) -I$(INCLUDE) -c add.c
sub.o: sub.c
	$(CC) -I$(INCLUDE) -c sub.c

