CFLAGS=-Wall -g
LDFLAGS=-Wall -g

all: liste liste2

liste: liste.o 
	gcc  ${LDLAGS} liste.o  -o liste

liste2: liste2.o 
	gcc  ${LDLAGS} liste2.o  -o liste2

liste.o: liste.c
	gcc ${CFLAGS} -c liste.c -o liste.o


clean:
	\rm -rf *.o *~ liste liste2

