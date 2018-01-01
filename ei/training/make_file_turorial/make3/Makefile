# Make using macro
# Here Header file is as <myMath.h> So use include
CC = gcc

INSDIR = /home/vinay/ei/training/make_file_turorial/make3


MYLIB = mylib.a

CFLAGS = -Wall

all: addDemo.o $(MYLIB)
	$(CC) $(CFLAGS) -o demo addDemo.o $(MYLIB) 

$(MYLIB): $(MYLIB)(add.o) $(MYLIB)(sub.o)
add.o: add.c
sub.o: sub.c

clean:
	-rm *.o
	-rm -r output

install:
	mkdir output 
	mv *.o output 
