demo: addDemo.o add.o sub.o
	gcc -o demo addDemo.o add.o sub.o
addDemo.o: addDemo.c myMath.h
	gcc -c addDemo.c
add.o: add.c
	gcc -c add.c
sub.o: sub.c
	gcc -c sub.c

