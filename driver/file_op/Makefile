CONFIG_MODULE_FORCE_UNLOAD=y
obj-m += fileop.o
all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	gcc -o test test.c
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	rm test
test:test.c
	gcc -o test test.c
	
