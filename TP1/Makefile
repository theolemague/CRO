CFFLAGS = -g -Wall -DDEBUG

all : main

main : main.o hanoi.o pile.o
	gcc ${CFLAGS} main.o hanoi.o pile.o -o main

main.o : main.c pile.h hanoi.h pile_type.h
	gcc ${CFLAGS} -c main.c -o main.o

hanoi.o : hanoi.c hanoi.h
	gcc ${CFLAGS} -c hanoi.c -o hanoi.o

pile.o : pile.c pile.h pile_type.h
	gcc ${CFLAGS} -c pile.c -o pile.o

clean :
	rm *.o

