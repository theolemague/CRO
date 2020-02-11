all : main

main : main.o hello.o
	gcc -Wall -L./lib main.o -o main -lhello
	./main

hello.o : ./src/util/hello.c ./include/hello.h
	gcc -c ./src/util/hello.c -I./include -o hello.o
	ar -crs ./lib/libhello.a hello.o

main.o : ./src/traitement/main.c ./include/hello.h
	gcc -Wall -c ./src/traitement/main.c -I./include -o main.o

clean :
	rm -f hello *.o