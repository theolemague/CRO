CFLAGS=-Wall


all: tabEntier


tabEntier: tabEntier.o
	gcc ${LDFLAGS} tabEntier.o -o tabEntier

tabEntier.o: tabEntier.c
	gcc ${CFLAGS} -c tabEntier.c -o tabEntier.o

clean:
	\rm -rf *.o tabEntier *~
