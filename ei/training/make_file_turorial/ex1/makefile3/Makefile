CC=gcc
CFLAFS= -I .
DEPS =myMath.h
%.o: %.c 
	@echo "abc"
	$(CC) -c -o $@ 	$< $(CFLAGS)
	@ls
	
demo:demo.o add.o sub.o
	@echo "xyz"
	$(CC) -o demo demo.o add.o sub.o $(CFLAGS)
	@ls
clean:
	rm *.o demo
