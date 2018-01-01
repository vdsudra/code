CC=gcc
CFLAGS=-I .

demo:demo.o add.o sub.o
	$(CC) -o demo demo.o add.o sub.o $(CFLAGS)
clean:
	rm *.o demo
