SRC=../src
INC=../inc
CFLAGS=-I$(INC)

SOURCE=$(wildcard $(SRC)/*.c)

OBJS=$(SOURCE:%.c=%.o)

demo: $(OBJS)
	@echo $(SOURCE)
	gcc -o demo $(CFLAGS) $(OBJS)
	@echo $(OBJS)
clean:
	rm  $(SRC)/*.o
	rm demo 
