CC=gcc
CFLAFS= -I .
DEPS =myMath.h
OBJ=demo.o add.o sub.o

%.o: %.c $(DEPS)
	@echo "abc"
	$(CC) -c -o $@ 	$< $(CFLAGS)
	@ls
	
demo:$(OBJ)
	@echo "xyz"
	$(CC) -o $@ $^ $(CFLAGS)
	@ls
clean:
	rm *.o demo
